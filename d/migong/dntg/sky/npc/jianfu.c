 
inherit NPC;
 
void create()
{
	set_name("�ั", ({"jian fu","fu"})); 
        set("gender", "����" );
	set("long", "�����ั��\n");
        set("age",40);
	set("title", "�����");
        set("str", 30);
        set("int", 20);
	set("con", 30);
	set("spi", 20);
        set("per", 15);
	set("class", "xian");
	set("attitude", "friendly");
        set("combat_exp", 20500);
  set("daoxing", 20500);

	set("max_qi", 1000);
	set("max_jing", 1000);
        setup();
        carry_object(__DIR__"xianpao")->wear();
}
 
