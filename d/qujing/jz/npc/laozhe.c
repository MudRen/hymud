//Cracked by Roath
inherit NPC;
string ask_book();
void create()
{
        set_name("����", ({"old man","lao zhe","man"}));
        set("gender", "����");
        set("age", 58);
        set("long","һ�����ع�ϡ�����ˣ���˵���Ͱ������д״ֽ�����򱨲�ƽ��");
        set("attitude", "friendly");
        set("per", 30);
        set("str", 30);
        set("combat_exp",2000);
	set("combat_exp",2000);	
        set("max_qi",300);
        set("max_jing",300);
        set("inquiry", ([
                "��״" : (: ask_book :),
                "״ֽ" : (: ask_book :),
                        ]) );
        setup();
}
string ask_book()
{
        object ob;
        object me = this_player();

        if(query_temp("no_zz")) 
        return "����û��״ֽ�ˡ�";

        ob = new("/d/qujing/jz/obj/paper");
        if(random(10)==1 && !query_temp("no_zz")) {
        ob->move(this_player());
        set_temp("no_zz",1);
        return "������������Ѫ���������д�õ�״ֽ����״ȥ�ɡ�";
                                          }
        else
        return "ƽ���޹ʣ���ʲô״����";
}
