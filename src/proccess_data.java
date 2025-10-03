public class Main {
  public static void main(String[] args) {
    // Document JSON Default Data
    json_data = new json_data;

    // Parse close file and add to obj storage
    open './src/default_data.json' | obj:json_data;

    // Find HTML file
    page = new page;
    page.href = './extra/james.html';

    // Find JS in page
    page.js = page.locateTag("script");
    catch error:
      do {
        page.js = page.locateElement("<script>...</scipt>");
        break(":before:", "inner");
      };

    // Run Proccess
    run();
  };
};
