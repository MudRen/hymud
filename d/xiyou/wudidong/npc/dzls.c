// Created by kuku@sjsh  2003.2
// �޵׶���������npc 

inherit NPC;
int ask_book();
int ask_blade();


void create()
{
        set_name("��������", ({"daza laoshu", "laoshu"}));
        set("age", 22);
        set("title","�޵׶�");
        set("gender", "����");
        set("int", 35);
        set("long","�����޵׶�ר�Ÿ�����͵���������������޵׶�����Ҫ����ѧϰ���������\n");
        set("attitude", "friendly");
        set("combat_exp", 40000);
        set("combat_exp", 100000);
        set("max_neili", 400);
        set("neili", 400);
        set("force_factor", 5);
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("literate", 150);
 
        setup();
        carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
        call_out("greeting", 1, this_player());
        ::init();
}

void greeting(object who) 
{
        if( !who || environment(who) != environment() ) return;
        if( who->query("family/family_name")!= "�ݿ�ɽ�޵׶�" ) return;
        tell_object(who,"�����������ĸ����㣺��Ҫ�޵׶��ı����������пհ��ʱ�(ask laoshu about book)�Ϳݹǵ�(ask laoshu about blade)��\n");  
}


