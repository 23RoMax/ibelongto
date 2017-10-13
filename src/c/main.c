#include <pebble.h>

static Window *s_main_window;
static TextLayer *s_header;
static TextLayer *s_name;
static TextLayer *s_street;
static TextLayer *s_city;
static TextLayer *s_phone_number;

static void main_window_load(Window *window) {
  // Get information about the Window
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  // Create the TextLayer with specific bounds
  s_header = text_layer_create(GRect(0, 0, bounds.size.w, 20));
  s_name = text_layer_create(GRect(0, 20, bounds.size.w, 40));
  s_street = text_layer_create(GRect(0,70, bounds.size.w, 60));
  s_city = text_layer_create(GRect(0,90, bounds.size.w, 80));
  s_phone_number = text_layer_create(GRect(0,110, bounds.size.w, 100));
  
  // Improve the layout to be more like a watchface
  // s_header
  text_layer_set_background_color(s_header, GColorBlack);
  text_layer_set_text_color(s_header, GColorClear);
  text_layer_set_text(s_header, "This Pebble belongs to:");
  text_layer_set_font(s_header, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  text_layer_set_text_alignment(s_header, GTextAlignmentCenter);
  // s_name
  text_layer_set_background_color(s_name, GColorClear);
  text_layer_set_text_color(s_name, GColorBlack);
  text_layer_set_text(s_name, "Maximilian Nebl");
  text_layer_set_font(s_name, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text_alignment(s_name, GTextAlignmentCenter);
  // s_street
  text_layer_set_background_color(s_street, GColorClear);
  text_layer_set_text_color(s_street, GColorBlack);
  text_layer_set_text(s_street, "Tambacher Weg 14a");
  text_layer_set_font(s_street, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  text_layer_set_text_alignment(s_street, GTextAlignmentCenter);
    // s_city
  text_layer_set_background_color(s_city, GColorClear);
  text_layer_set_text_color(s_city, GColorBlack);
  text_layer_set_text(s_city, "96450 Coburg");
  text_layer_set_font(s_city, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  text_layer_set_text_alignment(s_city, GTextAlignmentCenter);
    // s_phone_number
  text_layer_set_background_color(s_phone_number, GColorClear);
  text_layer_set_text_color(s_phone_number, GColorBlack);
  text_layer_set_text(s_phone_number, "004917620042329");
  text_layer_set_font(s_phone_number, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  text_layer_set_text_alignment(s_phone_number, GTextAlignmentCenter);


  
  // Add all as a child layer to the Window's root layer
  layer_add_child(window_layer, text_layer_get_layer(s_name));
  layer_add_child(window_layer, text_layer_get_layer(s_header));
  layer_add_child(window_layer, text_layer_get_layer(s_street));
  layer_add_child(window_layer, text_layer_get_layer(s_city));
  layer_add_child(window_layer, text_layer_get_layer(s_phone_number));
}

static void main_window_unload(Window *window) {

}

static void init() {
  // Create window element and assign to the pointer *s_main_window
  s_main_window = window_create();

  // Set window handlers
  window_set_window_handlers(s_main_window, (WindowHandlers) {
     .load = main_window_load,
    .unload = main_window_unload
  });
  
  // Show the window on the watch, with animation true
  window_stack_push(s_main_window, true);
}

static void deinit() {
  // Destroy Window
  window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}