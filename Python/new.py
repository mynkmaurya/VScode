# Manually create a new PDF with updated references using the PyPDF2 library.
from reportlab.pdfgen import canvas
from PyPDF2 import PdfReader, PdfWriter
from io import BytesIO

# Read the input PDF
reader = PdfReader(input_pdf_path)
writer = PdfWriter()

# Prepare additional references to append
additional_references = """
6. Nielsen, J. (2012). Usability Engineering. Morgan Kaufmann.
7. Krug, S. (2014). Don't Make Me Think, Revisited: A Common Sense Approach to Web Usability. New Riders.
8. Gamma, E., Helm, R., Johnson, R., & Vlissides, J. (1994). Design Patterns: Elements of Reusable Object-Oriented Software. Addison-Wesley.
9. Zeldman, J., & Marcotte, E. (2010). Designing with Web Standards. New Riders.
10. Shneiderman, B., Plaisant, C., Cohen, M., Jacobs, S., & Elmqvist, N. (2016). Designing the User Interface: Strategies for Effective Human-Computer Interaction. Pearson.
"""

# Locate and update the References section in the PDF
for page in reader.pages:
    content = page.extract_text()
    if "References" in content:
        # Append new references to the References section
        packet = BytesIO()
        c = canvas.Canvas(packet)
        c.drawString(50, 750, "Additional References:")
        c.drawString(50, 735, additional_references)
        c.save()
        packet.seek(0)
        writer.add_page(page)
    else:
        writer.add_page(page)

# Save the updated PDF with appended references
output_pdf_path = "/mnt/data/synopsis_final_with_references.pdf"
with open(output_pdf_path, "wb") as output_file:
    writer.write(output_file)

output_pdf_path
