// monk.c

inherit NPC;

void create()
{
        set_name("��ɮ", ({ "old monk" }) );
        set("gender", "����" );
        set("age", 74);
        set("long",
"������˿�������ʮ�����ˣ�ȴ�������塣\n");
        set("combat_exp", 1);
        set("attitude", "friendly");
        setup();
	carry_object(__DIR__"obj/jiasha")->wear();
}