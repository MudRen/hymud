 
inherit NPC;
 
void create()
{
	set_name("µä²¾", ({"dian bu"})); 
        set("gender", "ÄÐÐÔ" );
	set("long", "ÓùÂí¼àµä²¾¡£\n");
        set("age",40);
	set("title", "ÓùÂí¼à");
        set("str", 30);
        set("int", 20);
	set("con", 30);
	set("spi", 20);
        set("per", 15);
	set("class", "xian");
	set("attitude", "friendly");
        set("combat_exp", 8500);
  set("daoxing", 8500);

	set("max_qi", 1000);
	set("max_jing", 1000);
        setup();
         carry_object(__DIR__"xianpao")->wear();
}
 

ÿ