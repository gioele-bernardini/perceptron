from manim import *

class NeuralNetworkWithTenNeurons(Scene):
    def construct(self):
        # Definire la struttura della rete neurale con un offset più grande
        input_neurons = [Dot(point=UP*3 + LEFT*4 + DOWN*i*0.8) for i in range(10)]
        hidden_neurons = [Dot(point=LEFT*0 + DOWN*i*0.8) for i in range(10)]
        output_neurons = [Dot(point=DOWN*2 + RIGHT*4 + DOWN*i*0.8) for i in range(10)]

        input_layer = VGroup(*input_neurons)
        hidden_layer = VGroup(*hidden_neurons)
        output_layer = VGroup(*output_neurons)

        # Aggiungi i neuroni alla scena
        self.play(FadeIn(input_layer), FadeIn(hidden_layer), FadeIn(output_layer))

        # Collegare i neuroni con linee che rappresentano i pesi
        connections = VGroup()
        for input_neuron in input_layer:
            for hidden_neuron in hidden_layer:
                line = Line(input_neuron.get_center(), hidden_neuron.get_center())
                connections.add(line)
        
        for hidden_neuron in hidden_layer:
            for output_neuron in output_layer:
                line = Line(hidden_neuron.get_center(), output_neuron.get_center())
                connections.add(line)

        self.play(Create(connections))

        # Animare l'aggiornamento dei pesi
        for _ in range(3):  # Simulare 3 step di addestramento
            self.play(
                *[line.animate.set_color(RED) for line in connections],  # Cambia colore per rappresentare l'aggiornamento
                run_time=0.5
            )
            self.play(
                *[line.animate.set_color(WHITE) for line in connections],  # Ripristina il colore
                run_time=0.5
            )

        # Finalizzazione dell'animazione
        self.wait(2)

if __name__ == "__main__":
    from manim import * 
    scene = NeuralNetworkWithTenNeurons()
    scene.render()

