document.addEventListener('DOMContentLoaded', function() {
    // Utility function to validate number input
    function validateNumber(value) {
        const num = parseFloat(value);
        return !isNaN(num) && isFinite(num);
    }

    // Utility function to format result
    function formatResult(value) {
        return typeof value === 'number' ? value.toFixed(2) : value;
    }

    // Utility function to animate result change
    function animateResult(element, value) {
        element.style.transform = 'scale(1.1)';
        element.style.color = '#0d6efd';
        element.textContent = value;
        
        setTimeout(() => {
            element.style.transform = 'scale(1)';
            element.style.color = '';
        }, 200);
    }

    // Calculator functionality
    const calculatorOperations = {
        add: (a, b) => a + b,
        subtract: (a, b) => a - b,
        multiply: (a, b) => a * b,
        divide: (a, b) => b !== 0 ? a / b : 'Cannot divide by zero'
    };

    function performCalculation(operation) {
        const num1 = document.getElementById('num1').value;
        const num2 = document.getElementById('num2').value;
        const resultElement = document.getElementById('result');

        if (!validateNumber(num1) || !validateNumber(num2)) {
            animateResult(resultElement, 'Please enter valid numbers');
            return;
        }

        const result = calculatorOperations[operation](parseFloat(num1), parseFloat(num2));
        animateResult(resultElement, formatResult(result));
    }

    // Add event listeners for calculator buttons
    document.getElementById('add').addEventListener('click', () => performCalculation('add'));
    document.getElementById('subtract').addEventListener('click', () => performCalculation('subtract'));
    document.getElementById('multiply').addEventListener('click', () => performCalculation('multiply'));
    document.getElementById('divide').addEventListener('click', () => performCalculation('divide'));

    // Counter functionality with animation
    let count = 0;
    const countElement = document.getElementById('count');

    function updateCount(increment) {
        count += increment;
        countElement.style.transform = 'scale(1.2)';
        countElement.style.color = increment > 0 ? '#198754' : '#dc3545';
        countElement.textContent = count;
        
        setTimeout(() => {
            countElement.style.transform = 'scale(1)';
            countElement.style.color = '';
        }, 200);
    }

    document.getElementById('increment').addEventListener('click', () => updateCount(1));
    document.getElementById('decrement').addEventListener('click', () => updateCount(-1));

    // Temperature converter functionality
    const tempConversions = {
        celsiusToFahrenheit: (celsius) => (celsius * 9/5) + 32,
        fahrenheitToCelsius: (fahrenheit) => (fahrenheit - 32) * 5/9
    };

    function convertTemperature() {
        const fromUnit = document.getElementById('tempFrom').value;
        const toUnit = document.getElementById('tempTo').value;
        const fromValue = document.getElementById('tempFromValue').value;
        const toElement = document.getElementById('tempToValue');

        if (!validateNumber(fromValue)) {
            toElement.value = 'Invalid input';
            return;
        }

        let result;
        const value = parseFloat(fromValue);

        if (fromUnit === toUnit) {
            result = value;
        } else if (fromUnit === 'celsius' && toUnit === 'fahrenheit') {
            result = tempConversions.celsiusToFahrenheit(value);
        } else {
            result = tempConversions.fahrenheitToCelsius(value);
        }

        toElement.value = formatResult(result);
        toElement.style.backgroundColor = '#e8f0fe';
        
        setTimeout(() => {
            toElement.style.backgroundColor = '';
        }, 300);
    }

    document.getElementById('convertTemp').addEventListener('click', convertTemperature);

    // Add input validation and auto-conversion for temperature inputs
    document.getElementById('tempFromValue').addEventListener('input', function(e) {
        if (this.value && validateNumber(this.value)) {
            convertTemperature();
        }
    });

    // Add unit swap functionality
    document.querySelector('.bi-arrow-down-up').addEventListener('click', function() {
        const fromSelect = document.getElementById('tempFrom');
        const toSelect = document.getElementById('tempTo');
        const fromValue = document.getElementById('tempFromValue').value;
        const toValue = document.getElementById('tempToValue').value;

        // Swap units
        const tempUnit = fromSelect.value;
        fromSelect.value = toSelect.value;
        toSelect.value = tempUnit;

        // Swap values if they exist and are valid
        if (validateNumber(fromValue) && validateNumber(toValue)) {
            document.getElementById('tempFromValue').value = toValue;
            convertTemperature();
        }

        // Animate the swap icon
        this.style.transform = 'rotate(180deg)';
        setTimeout(() => {
            this.style.transform = '';
        }, 300);
    });
});
