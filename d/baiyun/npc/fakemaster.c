 // master.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("Ҷ�³�", ({ "master ye", "master" }) );
        set("nickname", HIC"һ������"NOR+HIR" �������"NOR);
        set("gender", "����" );
        set("age", 44);
        set("str", 50);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
       set("per", 40);
        set("agi",25);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );
        set("attitude","friendly");
        set("max_neili", 8000);
        set("force", 8000);
        set("force_factor", 30);
    set("max_qi",8000);
        set("max_jing",8000);
        set("max_jing",8000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "Ҷ�³���������֮�������۳���΢΢һЦ�����Ͻ�֮�ߣ�һ��������\n",
        }) ); 
        set("long",
"���Լ��������ݳ�ª��һ˫�۾���������ݣ���ȻҲĿ���Ƶ磬����ʵ�м���
��������֮�⡣\n"
        );
        create_family("���Ƴ�",1, "����");
        set("rank_nogen",1);
        set("ranks",({"��ͯ","С��ʿ","��ʿ","С����","����",
                      "С����","����","��ʦ",CYN"��ʦ"NOR,
                      CYN"����"NOR,CYN"����"NOR,HIC"��ʥ"NOR}));
        set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 }));
        set("combat_exp", 2000000);
        set("score", 200000);
        set("reward_npc", 1);
        set("difficulty", 10);
        set_skill("move", 150);

        set_skill("parry", 120);
        set_skill("dodge", 150);
        set_skill("force", 160);
        set_skill("literate", 130);
        set_skill("sword", 140);
        set_skill("unarmed",120);
        set_skill("changquan",120);
        set_skill("feixian-steps",140);
        set_skill("feixian-sword",140);
        set_skill("jingyiforce",60);
        map_skill("dodge", "feixian-steps");
        map_skill("sword", "feixian-sword");
        map_skill("force", "jingyiforce");
        map_skill("parry", "feixian-sword");
        map_skill("unarmed", "changquan");  
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/bsword")->wield();
        carry_object(__DIR__"obj/bcloth")->wear(); 
} 

void init()
{       
        ::init();
        add_action("do_killing", "kill");
    
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
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "baiyun"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N�����������¥�������������\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
int leave() {
        if (this_player()->query("class")!="assassin") return 0;
        message_vision(WHT"$N����һ������������Ƶ����������Ĳ����������������ģ����ǳ����߰ɣ�\n"NOR, this_object());
        message_vision(CYN"$N��Ȼ�������Ƶ��������黭������ͽ֮����������\n"NOR,this_object());
        return 1;
}  
