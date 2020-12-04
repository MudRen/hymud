inherit NPC;
#include <ansi.h>
string *make_msg = ({
    HIY "����΢Ц�Ŀ�����˵����лл����!\n\n" NOR,
    HIY "���������룬�ƺ�����Ӧ�ñ����������ֲ�֪����ô����á�\n\n" NOR,
    HIY "������һ�������! �Ͱ��ҵ�������Ӹ�����! \n\n" NOR,
});
void create()
{
        seteuid(getuid());
        set_name("����", ({ "arbao" }) );
        set("rank", "����");
        set("gender", "Ů��" );
        set("combat_exp", 4000);
        set("spi", 18);
        set("int", 19);
        set("con", 17);
        set_skill("stealing", 40);
        set_skill("dodge", 35);
        set_skill("dagger", 40);
        set_skill("sword", 30);
        set_skill("parry", 10);
        //set_skill("chunqiubifa", 20);
        //map_skill("parry", "chunqiubifa");
        set("age", 15);
        set("long",
                "���ʮ�塢�����С������ǡ��������ˣ���������Ȼ�����ֲ�\n"
                "�·�����ȴʮ���Ǹ��������ӣ�һ˫ˮ�����Ĵ��۾���µµ��ת\n"
                "��������ʱ�����㿴��ʹ�㲻��������Щ������\n");
        setup();
       	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();


        set("inquiry", ([
              "here" : "�������Լ��������İ����ѵ���֪�������\n",
              "name" : "�����������˼���ô���������\n", 
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
                  say( "ι ... �Ҷ��Ӻö�����û�гԵģ��Һ���԰����ѣ�\n");
                        break;
                case 1:
                  say( "��������΢Ц�� \n ˵������ ...��λ" +
RANK_D->query_respect(ob)
                   + "����������֪���������� ...��\n");
        }
}
int accept_object(object who, object ob)
{
     string objname;
     objname = (string)ob->name();
        if ( objname != "������")  {
           command("smile");
            say ( HIY "лл��?! �������˼!����лл�㡣\n" NOR);
           command("blush");
             return 1;
            }
        if( !who->query_temp("����/������") )  {
          call_out( "make_stage", 2, who, 0 );
            who->set_temp("����/������", 1);
         } else {
             say (HIY "���Ѿ������ˣ��ٴ�лл����! \n" NOR);
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
       obj = new(__DIR__"obj/comb");
       obj->move(who);
    return;
}
