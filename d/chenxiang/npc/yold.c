 // (C)1998-2000 Tie Yu
inherit NPC;
void create()
{
    set_name("����̫", ({ "yang","yang laotai" }) );
    set("gender", "Ů��" );
    set("title","�����޿�");
    set("long","����̫�����޿������쿿�ַ�Ϊ������ĺܿ�����\n");
    set("age", 75);
    set("combat_exp", 5);
    set("attitude", "friendly");
    set("chat_chance", 5);
    set("chat_msg", ({
        "����̫Ĩ��Ĩ���᣺�Ҷ�ѽ��˭���������Ұɣ�\n",
            }) );
    setup();
    carry_object("/clone/misc/cloth")->wear();
} 
int accept_object(object me, object obj)
{
    object ob;
    me->add_temp("marks/����̫",obj->value());
    if(me->query_temp("marks/����̫") > 49000 && !query("given"))
    {
        command("say �������Ǹ������ˣ�����һ��Խ��ɽ�İ��ޣ�ר�ſ��Ծĸ������ף��͸���ɣ�\n");
        ob= new(__DIR__"obj/arong");
//      set("given",1);
        ob->move(me);
        me->delete_temp("marks/����̫");
    }
    else command("say ������ﹻ�أ�\n");
    return 1;   
} 
/*
void reset()
{
delete("given");
}*/     
