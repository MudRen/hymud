 // waiter.c
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("������", ({ "ji furen" }) );
        set("gender", "Ů��" );
        set("age", 45);
//        set("title",RED  "ɱ��ׯ��"NOR);
        set("long",
                "һ�����صĺ���Ů�ӣ�����˵����ׯ�����ˣ�����˵����ׯ�����á�
���Դ�ʮ����ǰׯ���и�����ʧ���ᣬ���ׯ�����˾Ϳ�ʼ���Ī�����\n");
        set("combat_exp", 5000000);
        set("attitude", "friendly");
        set("reward_npc", 1);
        set("difficulty", 100);
        set("dex",150);
        set("str",150);
        set("per",50);
        set("fle",50);
        set("dur",50);
        set("con",50);
                set("max_qi", 15000);
        set("max_jing", 12000);
        set("neili", 32000);
        set("max_neili", 32000);
        set("jiali", 50);
        set("combat_exp", 9800000);
        set("score", 180000);


        set_skill("dodge",250);
        set_skill("parry",250);        
        set_skill("taiji-quan",250);        
        set_skill("unarmed",250);
        map_skill("unarmed","taiji-quan");

        set("force",3000);
        set("max_neili",3000);
        set("max_mana",10000);
        set("max_atman",10000);
        set("force_factor",30);

        setup();
        carry_object(__DIR__"obj/birdbox");
        carry_object(__DIR__"obj/wine");
        carry_object("/clone/misc/cloth")->wear(); 
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
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
message_vision("$N��ϸ������$n���㲻�����������㲻����������\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N��$n�����򸣣�����Ů����᷿�����˲����������������ذɡ�\n",this_object(),ob);
                        break;
                case 2:
message_vision("$N��������$nһ�ۣ��ݷ��������һ�ж��ǿա�\n",this_object(),ob);
                        break;
        }
}
int accept_object(object who, object ob,object obj){
        object me;   
        me=this_player();
    if( ob->name() == GRN"�޼���������"NOR) {
    	            obj = new(__DIR__"obj/wine");
                message_vision(HIY"$N��������"NOR + ob->name() + HIY"˵��������������������\n���㣡���㣡�����ڻ����ˣ�����Ϊ��׼���˾Ʋˣ��Դ��������ɡ���\n"+"$N��"NOR + obj->name() + HIY"����$n���С�\n", 
                            this_object(),this_player() );
                            obj = new(__DIR__"obj/wine");
                            obj->move(this_player());
                        //command("give taoqing-wine to " + me->query("id"));
    } else{
        return notify_fail("������ҡҡͷ˵�����Ҳ�Ҫ������� \n");
    }
        return 1;
} 
