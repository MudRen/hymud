// girl.c
inherit NPC;
#include <ansi.h>
string *make_msg = ({
    MAG "����Ů������Ŀ�����˵����лл����!\n\n" NOR,
    MAG "����Ů�Ӷ������˫�ۣ��·�Ҫ����������ġ�\n\n" NOR,
    MAG "����Ů�ӵ�����ѽ�����ȥ����ס��ɲ�����ͨ�Ľ���! \n\n" NOR,
    MAG "����Ů��ת�������������������������һ�Ҫɱ���㡣\n\n" NOR,
});
void create()
{
        set_name("����Ů��", ({ "girl" }) );
        set("con", 21);
        set("str", 19);
        set("spi", 22);
        set("per", 22);
        set("int", 20);
        set("gender", "Ů��" );
        set("combat_exp", 555000);
        set_skill("sword", 350);
        set_skill("dodge", 350);
        //set_skill("chunqiubifa", 150);
        set_skill("parry", 250);
        set_skill("blade", 70);
        set_skill("dagger", 70);
      //  map_skill("parry", "chunqiubifa");
        set("age", 19);
        set("long",
                "һ�������µ�Ů�ӣ���������Ͳ��ᳬ����ʮ�꣬��ò�䲻������ȴ\n"
                "����һ������֮����������Ȼ�������ꡣ\n" );
        setup();
   //     carry_object(__DIR__"obj/white_dress")->wear();
   //     carry_object(__DIR__"obj/slasher_sword")->wield();
        set("inquiry", ([
              "here" : "����ȥ�����ﲻ����Ӧ�����ĵط���\n",
              "name" : "�ٶ�����ɱ���㡣\n", 
              "��ͭ����" : "����ô֪���Ҷ��˷������ǲ�����͵�ˡ�\n", 
              "����" : "����ô֪���Ҷ��˷������ǲ�����͵�ˡ�\n", 
               ]) );
}
void init()
{
       object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        switch( random(2) ) {
                case 0:
                  say( "����Ů����ĵ�������ȥ��������ɱ���㣡\n");
                        break;
                case 1:
                  say( "����Ů��߳���������ѵ���׼��������\n");
        }
}
int accept_object(object who, object ob)
{
     string objname;
     objname = (string)ob->name();
        if ( objname != "��ͭ����")  {
           command("heng");
            say ( MAG "лл!��ϧ�Ҷ����û��Ȥ....\n" NOR);
           command("blush");
             return 1;
            }
        if( !who->query_temp("����Ů��/����") )  {
          call_out( "make_stage", 2, who, 0 );
            who->set_temp("����Ů��/����", 1);
         } else {
             say (HIY "��ô�ỹ�У��ѵ��ղ�����ҵ��Ǽٵ�! \n" NOR);
             return 1;
          }
          return 1;
}
void make_stage(object who, int stage)
{
     object obj;
     tell_object(who, make_msg[stage]);
     if( ++stage < sizeof(make_msg) ) {
         call_out( "make_stage", 2, who, stage );
         return;
     } else
       obj = new("/d/xueting/npc/obj/slasher_sword");
       obj->move(who);
    return;
}
