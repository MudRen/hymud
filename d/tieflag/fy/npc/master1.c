 // taolord.c
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int leave(); 
void create()
{
    set_name("��һ��", ({ "master lei", "master", "lei" }) );
    set("nickname", HIY"����"NOR);
    set("gender", "����");
    set("age", 44);
    set("long",
        "���꿪ɽ�������϶���������ס������󵱼ң�֮����϶���һ�������š�\n"
        "���ն��Ҿ�Ӣ����Ϊ���ű������������������������������ƽ��ɽ��\n");
    set("combat_exp", 5000000);
    set("score", random (20000)); 
    set("class", "emei");
    set("reward_npc", 1);
    set("difficulty", 30); 
    set("int", 30);
    set("cor", 20);
    set("cps", 30);
    set("spi", 30);
    set("fly_target",1);        
    set("neili", 3000);
    set("max_neili", 3000);
    set("force_factor", 100);
    set("atman", 1400);
    set("max_atman", 1400);
    set("mana", 2000);
    set("max_mana", 2000); 
    set("resistance/gin",70);
    set("resistance/kee",70);
    set("resistance/sen",99);
        
    set("inquiry",  ([
                "leave": (: leave :),
               ]));
    set("apprentice_available", 10);


      set("class", "bonze");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "zhixin" :), 
        }) );

        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);
        set("per", 20);

        set("max_qi", 4000);
        set("max_jing", 2000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jingli", 1500);
        set("max_jingli", 1500);

        set("combat_exp", 2000000);
        set("score", 1000);
        set_skill("persuading", 550);
        set_skill("throwing", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("finger", 200);
        set_skill("parry", 200);
        set_skill("strike", 200);
        set_skill("sword", 250);
        set_skill("blade", 200);
        set_skill("literate", 100);
        set_skill("mahayana", 500);
        set_skill("buddhism", 250);
        set_skill("jinding-zhang", 300);
        set_skill("tiangang-zhi", 300);
        set_skill("huifeng-jian", 300);
        set_skill("yanxing-dao", 300);
        set_skill("zhutian-bu", 300);
        set_skill("linji-zhuang", 250);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","yanxing-dao");
        map_skill("parry","huifeng-jian");
    setup(); 
    add_money("gold", random(2));
    carry_object("/clone/weapon/gangdao")->wield();
    carry_object("/clone/misc/cloth")->wear();
} 
void die()
{
    object ob;
    if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
    if(ob) 
        ob->set_temp("killed_master_shi",1);
    ::die();
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
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
        if(id_class == "emei"&& userp(victim)&&player!=victim)
        {
message_vision(HIW"$N����$n�ȵ���" + RANK_D->query_rude(player) 
                                                + "����ɱ" + RANK_D->query_self_rude(this_object()) 
                                                + "��ͽ�ܣ�ȥ���ɡ�\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
int leave() {
        if (this_player()->query("class")!="emei") return 0;
        message_vision(CYN"$N���γ�̾������һ��һ�����������ɸ���������\n"NOR, this_object(),this_player());
        message_vision(CYN"$N��Ц˵���߰ɣ����Ұ�����Ϊ�������Լ��ú���ĥ�ˡ�\n"NOR,this_object(),this_player());
        message_vision(CYN"$N˵��һ��Ե�֣����������ɵ��Ӿʹ������Űɣ�\n"NOR,this_object(),this_player());
        return 1;
}
