 //TIE
inherit NPC; 
void create()
{
        set_name("������", ({ "guo", "yang"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����һλ�������������ĸ��֣���������û��������\n");
        set("title", "��������");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("sword", 100);
        set_skill("dodge", 40);
        setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
} 
int recognize_apprentice(object ob)
{
        if( !ob->query("marks/guo") ){
                say("������������������û��....\n");
                return 0;
        } 
        return 1;
} 
int accept_object(object who, object ob)
{
        if(ob->query("id") == "guo sword")
        {
                who->set("marks/guo", 1);
                say("������˵�����ã��ã��ã�̫���ˣ���û����Ϊʦ��
��Ĳ��ܽ��㣬�����ֻ����������ǿ��Եģ�\n");
        if(!who->query("m_success/������"))
        {
                who->set("m_success/������",1);
                who->add("score",400); 
        } 
                return 1;
        }
        return 0; 
}   
