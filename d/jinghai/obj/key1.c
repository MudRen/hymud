inherit ITEM;

void create()
{
      set_name("铁闸钥匙", ({"tie key", "key"}));
      set_weight(100);
      if (clonep())
      set_default_object(__FILE__);
      else {
      set("unit", "把");
      set("long", "铜制的钥匙，用它可以开启通往地牢看守房的铁闸门。\n");
      }
      setup();
}

