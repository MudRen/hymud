
// room_guard.c
inherit NPC;


void create()
{
        set_name("ʿ��", ({ "guard" }) );
        set("title", "��Զ �߾�");
        set("gender", "����" );
        set("age", 25);
        set("long", "�㿴��һ���⺷�ı߾���\n");
     set("shen_type",-1);
          set("str", 15);
          set("con", 30);
          set("cor", 30);
          set("max_kee", 600);
          set("kee", 600);
        set("int", 14);
        set("combat_exp", 10000);
        set("attitude", "heroism");
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);


        setup();
        add_money("silver", 12);
        add_money("coin", 500);
	carry_object("/d/city/npc/obj/gangdao")->wield();
	carry_object("/d/city/npc/obj/tiejia")->wear();
}

