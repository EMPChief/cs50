document.addEventListener("DOMContentLoaded", function() {
    // Logikk for flervalgsspørsmål

    // Velg alle elementer med klassen 'option'
    const options = document.querySelectorAll('.option');
    
    // Hent tilbakemeldingselement for flervalgsspørsmål
    const feedbackElement1 = document.getElementById('feedback1');

    // Legg til en 'click' hendelseslytter til hvert alternativ
    options.forEach(option => {
        option.addEventListener('click', () => {
            // Sjekk om det klikkede alternativet har klassen 'correct'
            if (option.classList.contains('correct')) {
                // Hvis riktig, endre bakgrunnsfarge til grønn og vis "Correct!" tilbakemelding
                option.style.backgroundColor = 'green';
                feedbackElement1.textContent = 'Correct!';
            } else {
                // Hvis feil, endre bakgrunnsfarge til rød og vis "Incorrect!" tilbakemelding
                option.style.backgroundColor = 'red';
                feedbackElement1.textContent = 'Incorrect!';
            }
        });
    });

    // Logikk for fritekstsvar

    // Hent inndatafeltet for fritekstsvar
    const answerInput = document.getElementById('answer');
    
    // Hent knappen for å sjekke svaret
    const checkButton = document.getElementById('check');
    
    // Hent tilbakemeldingselement for fritekstsvar
    const feedbackElement2 = document.getElementById('feedback2');

    // Legg til en 'click' hendelseslytter til knappen 'Check Answer'
    checkButton.addEventListener('click', () => {
        // Hent brukerens inndata, konverter til små bokstaver og fjern ekstra mellomrom
        let answer = answerInput.value.toLowerCase().trim();

        // Sjekk om svaret er korrekt
        if (answer === 'internet explorer') {
            // Hvis riktig, endre inndatafeltets bakgrunn til grønn og vis tilbakemelding
            answerInput.style.backgroundColor = 'green';
            feedbackElement2.textContent = 'Correct! Internet Explorer was originally called Mosaic.';
        } else {
            // Hvis feil, endre inndatafeltets bakgrunn til rød og vis tilbakemelding
            answerInput.style.backgroundColor = 'red';
            feedbackElement2.textContent = 'Incorrect!';
        }
    });
});
