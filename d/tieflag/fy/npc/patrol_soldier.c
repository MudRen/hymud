#include <ansi.h>
inherit NPC;
string  summon_more( object who);
void create()
{
        set_name("Ѳ��ʿ��", ({ "police" }) );
        set("long",
"���Ǹ�����ִ��Ѳ�������ʿ��������ά�����Ƴ�����ΰ�,�������,\n"
"ǧ��Ҫ�����ǿ�������������ǰ�Ǹ�ʲô�ģ����Ƕ�һ��ͬ�ʡ�\n");
        set("attitude", "heroism");
//      set("vendetta_mark", "authority");
        set("str", 40+random(40));
        set("cor", 40);
        set("cps", 25);
        set("class","wudang");
        set("combat_exp", 1000000+random(2000000));
        set("chat_chance_combat", 45);
        set("chat_msg_combat", ({
                "Ѳ��ʿ���ȵ�������������������־͸���\n",
                (: perform_action, "sword.chanzijue" :),
                (: summon_more(this_object()) :),
        }) );
        set_skill("unarmed", 70+random(100));
        set_skill("sword", 100+random(50));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 150+random(100));
        set_skill("changquan",200);
        set_skill("lonely-sword",200);
        map_skill("sword","lonely-sword");
        map_skill("unarmed","changquan");
        set_temp("apply/attack", 70);
                set_temp("apply/dodge", 70);
                set_temp("apply/parry", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 30+random(200));
        set_temp("apply/move", 100);
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );    
        setup(); 
        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/sword")->wield();
} 
void init() {
        object ob;
        ::init();
        if(interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_killing", "kill");
} 
void greeting(object ob) {
        
        string where;
        if(!ob || environment(ob) != environment()) {
                return;
        }
        
/*      if (n==0) say("Ѳ��ʿ��˵:����������ȥ������,�¸ں�ȥǧ��¥���ɷ���.\n");
        else if (n==1) say("Ѳ��ʿ��Ц������˵:�����ط��Ƴǽ�ͨ����.\n");
        else if (n==2) say("Ѳ��ʿ���ѳ���������һ��,���˸�����.\n");
        else if (n==4) say("Ѳ��ʿ���㽵�˵�����꾫�������˰�����֪��С�������ˡ�\n");
        else if (n>10) { say( "moving"); this_object()->random_move();} */ 
        switch( random(15)){
                case 0:
                        say("Ѳ��ʿ��˵:����������ȥ������,�¸ں�ȥǧ��¥���ɷ���.\n");
                        break;
                case 1:
                        say("Ѳ��ʿ��Ц������˵:�����ط��Ƴǽ�ͨ����.\n");
                        break;
                case 2:
                        say("Ѳ��ʿ���ѳ���������һ��,���˸�����.\n");
                        break;
                case 3: 
                        say("Ѳ��ʿ��˵:ǧ��¥û�����Ѻã������ѵĹ����Ǹ���ζ����\n");
                        break;
                case 4:
                        say("Ѳ��ʿ���㽵�˵�����꾫�������˰�����֪��С�������ˡ�\n");
                        break;  
           }
        where=file_name(environment(this_object()));
//      say ("���"+where+"\n");        
        if (where[3]!='f') this_object()->move("/d/tieflag/fy/fysquare");
        if (random(3)>1) this_object()->random_move();
        
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        if(userp(victim)&& victim!=player)
        {
            message_vision(HIW"$N����$n�ȵ����󵨿�ͽ,����������ɱ��,����������־͸�!\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
string summon_more(object who)
{
        int i;
        object *enemy;
        object another;
        seteuid(getuid());
        if (random(3)) {
                message_vision(HIW"$N��е�������ס�ˣ������ү��!\n"NOR, this_object());       
                another = new(__DIR__"patrol_officer");
                another->move(environment(who));
                message_vision(HIY"Ѳ���ڹ����˹�����\n"NOR, this_object() );
           message_vision(HIY"Ѳ���ڹٺȵ����η����񣬾����ڷ��Ƴ������ң�\n"NOR,this_object());   
                enemy = who->query_enemy();
                i = sizeof(enemy);
                while(i--) {
                        if( enemy[i] && living(enemy[i]) ) {
                        another->kill_ob(enemy[i]);
                        enemy[i]->kill_ob(another);
                        another->set_leader(enemy[i]);
                        }
                }
                return "1";
        }
        return "0";
}   
