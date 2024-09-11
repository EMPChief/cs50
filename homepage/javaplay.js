document.addEventListener('DOMContentLoaded', function() {
    // Kalkulatorfunksjonalitet
    // Håndterer klikk på "add" knappen for addisjon
    document.getElementById('add').addEventListener('click', function() {
        // Henter verdiene fra inputfeltene og konverterer dem til flyttall
        const num1 = parseFloat(document.getElementById('num1').value);
        const num2 = parseFloat(document.getElementById('num2').value);
        // Beregner summen av de to tallene
        const result = num1 + num2;
        // Viser resultatet i elementet med id 'result'
        document.getElementById('result').textContent = 'Resultat: ' + result.toFixed(2);
    });

    // Håndterer klikk på "subtract" knappen for subtraksjon
    document.getElementById('subtract').addEventListener('click', function() {
        // Henter verdiene fra inputfeltene og konverterer dem til flyttall
        const num1 = parseFloat(document.getElementById('num1').value);
        const num2 = parseFloat(document.getElementById('num2').value);
        // Beregner differansen mellom de to tallene
        const result = num1 - num2;
        // Viser resultatet i elementet med id 'result'
        document.getElementById('result').textContent = 'Resultat: ' + result.toFixed(2);
    });

    // Håndterer klikk på "multiply" knappen for multiplikasjon
    document.getElementById('multiply').addEventListener('click', function() {
        // Henter verdiene fra inputfeltene og konverterer dem til flyttall
        const num1 = parseFloat(document.getElementById('num1').value);
        const num2 = parseFloat(document.getElementById('num2').value);
        // Beregner produktet av de to tallene
        const result = num1 * num2;
        // Viser resultatet i elementet med id 'result'
        document.getElementById('result').textContent = 'Resultat: ' + result.toFixed(2);
    });

    // Håndterer klikk på "divide" knappen for divisjon
    document.getElementById('divide').addEventListener('click', function() {
        // Henter verdiene fra inputfeltene og konverterer dem til flyttall
        const num1 = parseFloat(document.getElementById('num1').value);
        const num2 = parseFloat(document.getElementById('num2').value);
        // Sjekker om divisor (num2) er ulik null for å unngå deling med null
        if (num2 !== 0) {
            // Beregner kvotienten av de to tallene
            const result = num1 / num2;
            // Viser resultatet i elementet med id 'result'
            document.getElementById('result').textContent = 'Resultat: ' + result.toFixed(2);
        } else {
            // Viser feilmelding hvis divisor er null
            document.getElementById('result').textContent = 'Feil: Divisjon med null';
        }
    });

    // Øke/Redusere funksjonalitet
    let count = 0; // Initialiserer tellevariabelen

    // Håndterer klikk på "increment" knappen for å øke tellevariabelen
    document.getElementById('increment').addEventListener('click', function() {
        count++; // Øker tellevariabelen med 1
        // Oppdaterer visningen av tellevariabelen i elementet med id 'count'
        document.getElementById('count').textContent = count;
    });

    // Håndterer klikk på "decrement" knappen for å redusere tellevariabelen
    document.getElementById('decrement').addEventListener('click', function() {
        count--; // Reduserer tellevariabelen med 1
        // Oppdaterer visningen av tellevariabelen i elementet med id 'count'
        document.getElementById('count').textContent = count;
    });

    // Temperaturkonverterer funksjonalitet
    // Håndterer klikk på "convertTemp" knappen for temperaturkonvertering
    document.getElementById('convertTemp').addEventListener('click', function() {
        // Henter hvilken temperatur enhet vi konverterer fra og til
        const tempFrom = document.getElementById('tempFrom').value;
        const tempTo = document.getElementById('tempTo').value;
        // Henter verdien fra inputfeltet for temperatur å konvertere
        const valueFrom = parseFloat(document.getElementById('tempFromValue').value);

        let result;

        // Konverterer temperatur basert på valgt enhet
        switch(tempFrom) {
            case 'celsius':
                switch(tempTo) {
                    case 'celsius':
                        result = valueFrom; // Ingen konvertering hvis begge enheter er Celsius
                        break;
                    case 'fahrenheit':
                        result = (valueFrom * 9/5) + 32; // Konverterer Celsius til Fahrenheit
                        break;
                }
                break;
            case 'fahrenheit':
                switch(tempTo) {
                    case 'celsius':
                        result = (valueFrom - 32) * 5/9; // Konverterer Fahrenheit til Celsius
                        break;
                    case 'fahrenheit':
                        result = valueFrom; // Ingen konvertering hvis begge enheter er Fahrenheit
                        break;
                }
                break;
        }

        // Viser det konverterte resultatet i inputfeltet for den nye temperaturen
        document.getElementById('tempToValue').value = result.toFixed(2);
    });
});
