from manim import *

class AnimatedCircle(Scene):
  def construct(self):
    # Create an initial circle with radius 1
    circle = Circle(radius=1, color=BLUE)

    # Add the circle to the scene
    self.play(Create(circle))

    # Animation to expand and contract the circle cyclically
    self.play(circle.animate.scale(2), run_time=2)
    self.play(circle.animate.scale(0.5), run_time=2)

    # Another animation to rotate the circle
    self.play(Rotate(circle, angle=PI), run_time=2)

    # Final animation where the circle gradually fades out
    self.play(FadeOut(circle))

    # Wait for a moment before ending the scene
    self.wait()

