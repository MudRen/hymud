//qigai.c

inherit NPC;

int ask_yi( object me );
void create()
{
    set_name("��ؤ", ({ "qi gai" }) );
    set("gender", "����" );
    set("age", 23);
    set("long", "һ���������۵�������ؤ��\n");
    set("combat_exp", 100);
    set("str", 27);
    set("force", 200);
    set("max_force", 200);
    set("force_factor", 2);
    setup();
    set("chat_chance", 50);
    set("chat_msg", ({
   "��ؤ˵�������ĵĴ�ү�ġ� ����Ҫ���ļ���Ǯ�ɡ�\n",
   "��ؤ������ش��˸���Ƿ��\n",
   "��ؤͻȻ��ɫһ�������ĵ�˵���������粨��ѽ������\n",
   "��ؤ����׽ס�����ϵ�ʭ�ӣ��������������û�����⣬ȫ�����Ǹ�ҧ���ˡ� \n",
   "��ؤ˵������˵���Ϻ�֮����һ���͵������о�����.\n",
        (: random_move :)
     }) );
    set("inquiry", ([
        "�״��" : (: ask_yi :),
    ]) );
}

int accept_object(object me, object obj)
{
     command("smile");
     command("chat ��л��λ" + RANK_D->query_respect(me)+"��, �����粨�ն����⼸���Ҫע����ѽ������\n");
     command("say ��л��λ" + RANK_D->query_respect(me) +
               "��������һ�����кñ��ģ�");
     return 1;
}
int accept_fight(object me)
{
     command("say " + RANK_D->query_respect(me) +
             "������С������뿪��\n");
     return 0;
}
     
int ask_yi( object me )
{
     write("������������.....���������ʲô?....��ؤ������һ��\n");
     return 1;
}
