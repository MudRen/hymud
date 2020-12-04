
inherit ITEM;

void create()
{
   set_name("怒目金刚", ({ "numu jingang","jingang","foxiang" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "座");
     set("material", "iron");
     set("long", "这是一座怒目金刚的佛像，看起来非常威严。\n");
   }
   setup();
}

int is_get_of(object ob,object obj)
{
   ob->set("jing",0);
   ob->set("sen",0);
   ob->set("qi",0);
   return notify_fail("你费了半天尽，发现根本扛不动这个佛像！\n");
}

string long()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("perform_quest/fumo_action1")||
      ob->query("perform_quest/fumo"))
   return query("long");
   ob->set("perform_quest/fumo",1);
   return "你看着怒目金刚佛像，从中领悟出了伏魔杖法的绝学！";
}