#include <ansi.h>
inherit F_MASTER;
inherit NPC;
int force_convert();
int leave();
void create() 
{
    set_name("��÷��ʦ", ({ "master kumei", "kumei","master"}));
    set("long", 
        "
����һ���׷��ԲԵ��ϸ���һ�Ÿɿ����������������˰̣�����ȱ�˰����
�۾�Ҳ����һֻ��ʣ�µ�һֻ�۾��뿪��ϣ�����֮�䣬���Ⱪ�䣬����˭Ҳ
���ұ��ӡ������Ӻ���С����ȴ����˵�����������ϣ�����˭��ֻҪ������ 
һ�ۣ���˵������������ѹ��Щ��
\n"
        );
    set("nickname", HIW "���ɹ�"NOR);
    set("gender", "Ů��");
    set("class","huashan");
    create_family("��ɽ��", 16, "����");
    set("rank_nogen",1);
    set("student_title","����");
    set("reward_npc", 1);
    set("difficulty", 5);
    set("age", 59);
    set("int", 30);
    set("per", 3);
    set("con", 25);
    set("str",28);
    
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
        set("inquiry", ([
//              "hanmei-force" : (: force_convert :),
//              "��÷�ķ�" : (: force_convert :),
                "leave" : (: leave :),
        ])); 
        
        
    set("ranks",({"����","С��","����","����","����",WHT"����"NOR,WHT"��ʥ"NOR,HIW"����"NOR}));
    setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}  
void attempt_apprentice(object ob)
{
    if (ob->query("gender")=="����") {
           command("say ��ɽֻ��Ů��Ϊͽ��\n");
        return;
    }   
    if (ob->query_skill("sword",1) < 19) {
         command("say  ��Խ�����֪���٣���Ȼ�������ң�");
                return;
    }
    if ((int)ob->query_skill("move",1) < 19 ) {
        command("say ���µ����ƺ�����ѧ�䰡��");
                return;
    }
/*    if ((int)ob->query("age") > 15 ) {
        command("say ��ν��׳��Ŭ�����ϴ�ͽ�˱����ҿ���������ѧһ��ûʲôǰ;��");
                return;
    }*/ 
    command("recruit " + ob->query("id"));
} 
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huashan");
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
           if(id_class == "huashan"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N��$n�ȵ���ƶ���ͽ�ܣ��ݲ��ø������̣ܽ�\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
int leave() {
        if (this_player()->query("class")!="huashan") return 0;
        message_vision(CYN"$N��Цһ��������ɽ��Ȼ�������ĵ��ӡ���\n"NOR, this_object());
        message_vision(CYN"$N˵����÷�ķ���ժ���ֵ��ؾ�������¡�\n"NOR,this_object());
        return 1;
}  
