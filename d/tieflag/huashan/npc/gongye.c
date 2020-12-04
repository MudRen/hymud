 // hawktrainer.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int train_animal();
void create()
{
        set_name("��ұ��", ({ "gongye chang","gongye" }) );
        set("gender", "����" );
        set("age", 34);
        
        set("long", @LONG
�����۾��������ŵġ��ƺ���Զ�����ڲ������ʲô�� 
LONG
);
        set("skill_public",1);
        set("inquiry",([
        "ѵ����" : (: train_animal :),
        "animal training" : (: train_animal :),
    ]) );
     set("neili", 36400);
        set("max_neili", 36400);
        set("jiali", 50);
        set("max_qi",18200);
        set("max_jing",15200);

        set("combat_exp", 5400000);
        set("shen", 20000);
        set_temp("xunshan", 200);
        set("apprentice_available", 3);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jm" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jie" :),
                (: perform_action, "sword.xian" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: exert_function, "powerup" :),
        }) );


        set_skill("unarmed", 180);
        set_skill("sword", 290);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 200);
        set_skill("huashan-sword", 290);
        set_skill("zixia-shengong", 320);
        set_skill("hunyuan-zhang", 290);
        set_skill("poyu-quan", 290);
        set_skill("feiyan-huixiang", 290);
        set_skill("pixie-sword",280);
        set_skill("zhengqijue",200);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");
        set("combat_exp", 10000000);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
        object me;
        ::init();
        if(interactive(me = this_player()) && !is_fighting() && userp(me))
        {
                        remove_call_out("greeting");
                        call_out("greeting", 1, me);
                        
        }
} 
int greeting(object me)
{
        object crow;
        if( !me || environment(me) != environment() ) return 0;
        if (random(3) || me->query("per")<=15)
        {
        message_vision("$N����$nһ�ۣ�������ֹ�� \n",this_object(),me);
        }else
        {
                if (crow = present("crow",environment()))
                {
                        message_vision("$N����$nһ�ۣ�Ц��$n˵������֪������˵ʲô������˵��"+YEL"\n ��ұ�� ��ұ�� ,\n �º�ˤ��һͷ�ǡ�\n ��ʳ�⣬��ʳ������ \n"NOR,this_object(),me);
                        crow->followme(me);
                }
        }
        
}
void accept_player(object player)
{
        object wolfmeat;
        if (player && present(player,environment()))
        {
                message_vision("��һ�������$N��ʰ�������ǡ�\n",this_object());
                message_vision("$N��$n���������������Ÿ��ҵ���ѻ��������㡣��\n",this_object(),player);
                wolfmeat = new(__DIR__"obj/wolfmeat");
                if (wolfmeat->move(player))
                {
                        message_vision("$N�ݸ�$nһ�����⸬��\n",this_object(),player);
                }
                if( player->query_temp("followcrow") && !player->query("marks/getwolf")) 
                {
                        message_vision("$N��������һֱ�����ҵ�ѵ����ʧ������λ"+ RANK_D->query_respect(player) +"������ͶԵ��
�����������ҿ��Խ��㼸�֡���\n",this_object());
                        player->set("marks/getwolf",1);
                        player->delete_temp("followcrow");
                } 
        }
} 
int accept_object(object who, object ob)
{
        if(ob->query("id") != "deadwolf")
    {
                return 0;
    }
    message_vision("$NЦ�����$n��������λ"+ RANK_D->query_respect(who) +"���Ǵ���!��\n",this_object(),who);
        message_vision("$N���˵ؽӹ����ǣ���ʼ��Ƥ���\n \n",this_object());
        call_out("accept_player",2,who);
        return 1;
}  
int train_animal()
{
        message_vision("$N������ѵ������һ�ź����õļ��ܣ������������ѵ��������Ϳ�ѵ�����ޣ������������㣬Ϊ����񡣡�\n", this_object());
        return 1;
}
int recognize_apprentice(object ob)
{
        if (this_player()->query("marks/getwolf"))
                return 1;
        else
                return 0;
}     
