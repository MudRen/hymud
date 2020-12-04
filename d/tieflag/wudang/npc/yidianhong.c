#include <ansi.h>
int give_silk();
inherit NPC;
void create()
{
        set_name("��ԭһ��"HIR"��"NOR, ({ "yidian hong", "hong"}) );
        set("title", "����һ���" );
        set("gender", "����" );
        set("age", 35);
        set("long", 
"һϮ���£��������ң���һ˫�۾�ȴ������磬ð��Ұ�ް���̹⡣���˱�\n�����µ�һɱ����ԭһ��졣\n");
        set("combat_exp", 5000000);
        set("str",40);
        set("attitude", "friendly");
        set_skill("unarmed", 350);
  //      set_skill("dragonstrike",200);
        set_skill("lefthand-sword",150);
        set_skill("dodge", 140);
        set_skill("fall-steps",160);
        set_skill("sword",200);
        set_skill("move",200);
        set_skill("sharen-sword",370);
//        map_skill("unarmed","dragonstrike");
        map_skill("sword","sharen-sword");
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps");
        
        set("force_factor",80);
        set("neili",1000);
        set("max_neili",1000);
         
        set("chat_chance_combat", 30);
        set("chat_msg_combat",  ({
            (: perform_action, "sword.sharenruma" :)
            }) );
        
        
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
    carry_object(__DIR__"obj/bloodsword")->wield();
}  
void win_enemy(object loser)
{
    message_vision(HIB"\n��ԭһ�����Ц����ʢ��֮�£���ʵ�Ѹ���\n"NOR,loser);
        command("sigh");
        loser->set("���_quest6","ʧ��");
} 
void lose_enemy( object winner)
{
    message_vision(HIR "\n\n��ԭһ���ҧҧ������Ȼ��Цһ��������������Ȼ�����鴫�����������\n"NOR,winner);
        winner->set("���_quest6","�ɹ�");
} 
int accept_fight(object me)
{
        object skinmask;
        object who;
        
        who=this_object();
        me=this_player();
        
        if (this_object()->is_fighting() || this_object()->is_busy())
                return notify_fail("��ԭһ�������æ���أ�û�պ�����\n");
                
        if(me->query("���_quest5")!="�ɹ�") return 0;
        if(!skinmask=present("cloth",me)) return 0;
        if((!skinmask->query("equipped"))||(!skinmask->query("tianfeng_skinmask")))
                return 0;
                
        if (who->query("qi")<who->query("max_qi") || who->query("eff_kee")<who->query("max_qi")
         || who->query("jing")<who->query("max_jing") || who->query("eff_jing")<who->query("max_jing"))
                {tell_object(this_player(),"��ԭһ�����������,û������.\n");
                return 0;
                }
        
        message_vision(HIY"��ԭһ�����������һ����,��������ã�������ʿ���ε���\n"NOR,me);
        return 1;
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
        if(victim->query("id")=="hong" || victim->query("id")=="yidian hong")
        {
            this_object()->remove_all_enemy();
            command ("say �ã���ɱ��!");
            return 0;
        } 
    }
    return 0;
} 
void init()
{
        ::init();
        add_action("do_killing", "kill");
                                                
} 