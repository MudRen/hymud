inherit NPC;inherit F_DEALER;


void create()
{
//   ("zhangshengshou");
        set_name("��ʥ��", ({"zhang shengshou", "zhang", "boss"}));
        set("title", "���ֻش�");
        set("gender", "����");
        set("age", 37);
        set("long",
"��ʥ�ֳ��������ҩ�ĵķ�����ҽ��Ҳ���˵á�\n");
        set("qi", 300); 
        set("max_qi", 300);
        set("jing", 200);
        set("max_jing", 200);
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("env/wimpy", 50);
      

        set_skill("literate", 70);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
      setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("gold", 1);
}






