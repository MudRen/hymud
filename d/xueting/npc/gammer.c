// gammer.c
inherit NPC;
#include <ansi.h>
string *make_msg = ({
    HIB "Ϲ����̫��΢Ц��˵�����ٺ٣��ǲ���ϲ������Ů��!\n\n" NOR,
    HIB "Ϲ����̫�������룬˵����лл�������ҵ�����.......\n\n" NOR,
    HIB "Ϲ����̫�ŵ��˵�ͷ���� �Ͱ������������Ϊл���! \n\n" NOR,
});
void create()
{
        set_name("Ϲ����̫��", ({ "blind gammer", "gammer" }) );
        set("con", 21);
        set("cor", 22);
        set("rank", "����");
        set("gender", "Ů��" );
        set("combat_exp", 8000);
        set_skill("staff", 50);
        set_skill("stealing", 70);
        set_skill("dodge", 90);
        set_skill("blade", 30);
        set_skill("sword", 30);
        set_skill("unarmed", 50);
        set_skill("dagger", 70);
        set("age", 66);
        set("long",
                "һ��Ϲ���۾�����̫�ţ��������ƣ�����ȴ����һ�����еĸо���\n");
        set("inquiry", ([
              "here" : "�ٺ٣��������㲻�ʣ�ƫƫ�����ǲ�����ʲô��ͼ����\n",
              "����" : "�����ҵı�����Ů��\n", 
               ]) );
        set("chat_chance", 8);
        set("chat_msg", ({
                "Ϲ����̫���૵�˵����������������\n",
                "Ϲ����̫�Ų��������ƺ�������ʲ�ᡣ\n",
              //  (: random_move :)
        }) );
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                "Ϲ����̫�Žе����������ж������۸������ģ����������\n",
                (: random_move :),
        }) );
        setup();
       
        carry_object(__DIR__"obj/cane")->wield();
        carry_object("/clone/misc/cloth")->wear();
}
void relay_say(object ob, string arg)
{
        if( arg == "����" ) 
        command("say ��������˵������������ǲ���ƭ���أ�" );
}
int accept_fight(object me)
{
        if( (string)me->query("rank")=="����" ) {
                command("nod");
                command("say ���аɡ�");
                return 1;
        }
        command("say �Ҷ��������޶ã�������ұ��ԣ��� ...��");
        return 0;
}
int accept_object(object who, object ob)
{
     string objname;
     objname = (string)ob->name();
        if ( objname != "��ľ����")  {
           command("heng");
            say ( HIY "�����֤��ʲô��֤��������˰�����\n" NOR);
           command("shake");
             return 1;
            }
        if( !who->query_temp("gammer/����") )  {
          call_out( "make_stage", 2, who, 0 );
            who->set_temp("gammer/����", 1);
         } else {
             say (HIB "��ô���ѵ��㻹��Ҫл��̰�İ�! \n" NOR);
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
       obj = new(__DIR__"obj/syndicator");
       obj->move(who);
    return;
}
