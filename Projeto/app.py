from flask import Flask, render_template, jsonify
import serial
import time

# Tenta conectar ao Arduino 
try:
    # ATENÇÃO: Verifique a porta COM correta no seu IDE do Arduino [cite: 68, 69]
    arduino = serial.Serial('COM4', 9600, timeout=1) 
    time.sleep(2) # Espera a conexão serial estabilizar 
    print("Arduino conectado com sucesso.")
except serial.SerialException as e:
    print(f"Erro ao conectar com o Arduino: {e}") 
    arduino = None 

app = Flask(__name__) 

# Rota principal: Renderiza a página index.html [cite: 14]
@app.route('/')
def index():
    return render_template('index.html')


# --- NOSSA NOVA ROTA ---
# Rota para buscar os dados do sensor
@app.route('/get_data')
def get_data():
    if arduino:
        try:
            arduino.write(b'T') # Envia o comando 'T' para pedir os dados
            time.sleep(0.1) # Dá um tempo para o Arduino responder
            
            data_line = arduino.readline().decode('utf-8').strip()
            
            if data_line and data_line != "ERRO" and ";" in data_line:
                # Separa os valores "temp;umid"
                temperatura, umidade = data_line.split(';')
                return jsonify(temperatura=float(temperatura), umidade=float(umidade))
            else:
                return jsonify(error="Falha ao ler sensor"), 500

        except Exception as e:
            print(f"Erro na leitura serial: {e}")
            return jsonify(error="Erro serial"), 500
            
    return jsonify(error="Arduino nao conectado"), 500


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000)