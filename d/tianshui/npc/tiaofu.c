// tiaofu.c

inherit NPC;

void create()
{
        set_name("����", ({ "tiao fu", "porter" }) );
        set("gender", "����" );
        set("age", 20+random(15));
        set("long",
                "���Ǹ���ʵ�ͽ��������򣬳��ð�����Բ��һ���⡣\n");
        set("combat_exp", 1500);
        set("attitude", "heroism");

        setup();
        carry_object("/clone/misc/cloth")->wear();
}