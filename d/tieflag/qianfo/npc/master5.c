 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <combat.h>
int kill_him();
int chuanren();
int leave();
void create()
{
    set_name("�δ�", ({ "master renci", "master"}) );
    set("nickname", HIR "ǰ�ΰ���"NOR);
    set("gender", "����" );
    set("class","beggar");
    set("reward_npc", 1);
    set("difficulty", 15);
    set("age", 64);
    set("per", 25);
    set("int",30);
    set("str",36);
    set("attitude","friendly");
    
    set("max_neili", 1000);
    set("neili", 1000);
    set("force_factor", 90);
    
    set("long", "�δ���ؤ���ǰ�ΰ�����ֻ���������ಡ����λ���Ϲ�\n");
    create_family("ؤ��", 6, "ǰ�ΰ���");
    set("rank_nogen",1);
    set("ranks",({"�������","һ������","��������","��������","�Ĵ�����",
                      "�������","��������","�ߴ�����","�˴�����",WHT"�Ŵ�����"NOR,
                      WHT"����"NOR,HIW"��ͷ���"NOR}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 }));     
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.xianglongwuhui" :)
            }) );
        set("resistance/kee",50);
        set("resistance/gin",40);
        set("resistance/sen",40);
        
    set("combat_exp", 4000000);
    
  	set("qi", 25000);
	set("max_qi", 25000);
	set("jing", 22400);
	set("max_jing", 22400);
	set("neili", 58000);
	set("max_neili", 58000);
	set("jiali", 300);
	
	set("combat_exp", 8000000);
	set("score", 200000);
	set("shen", 100000);
	 
		set_skill("fengmo-zhang",380);
	set_skill("liuhe-zhang",380);
	set_skill("strike",390);
	set_skill("force", 300);             // �����ڹ�
	set_skill("huntian-qigong", 380);    // ��������
	set_skill("unarmed", 260);           // ����ȭ��
	set_skill("xianglong-zhang", 380);   // ����ʮ����
	set_skill("dodge", 260);      	     // ��������
	set_skill("xiaoyaoyou", 380);        // ��ң��
	set_skill("parry", 260);             // �����м�
	set_skill("staff", 380);             // ��������
	set_skill("dagou-bang", 380);        // �򹷰���
	set_skill("begging", 380);           // �л�����
	set_skill("checking", 380);          // ����;˵
	set_skill("training", 380);         // Ԧ����
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.zhuan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield yuzhu zhang") :),
                (: command("wield yuzhu zhang") :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );

     
    set("inquiry", ([
        "�Ϲ���" : (: kill_him :),
        "master nangong" : (: kill_him :),
        "chuanren" : (: chuanren :),
        "����" : (: chuanren :),
        "leave" : (: leave :),
    ]));
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
    setup();
    carry_object(__DIR__"obj/9bagcloth")->wear();
        set_temp("apply/dodge",200);
        
}
void init(){
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
            remove_call_out("greeting");
            call_out("greeting", 2, ob);
        }
        add_action("do_killing", "kill");
} 
void greeting(object ob){
        if( !ob || environment(ob) != environment() ) return;
        if(!environment(this_object())->query("have_staff")) return;
        message_vision("\n$N��ΡΡ��̧��ͷ���˿�$n��̾�˿�����������ʱ�����ҵ���ؤ�ﴫ�ˣ�\n",
                        this_object(), ob); 
        message_vision("����ؤ�ﲻ�������֮�֡�������\n", this_object());
} 
void attempt_apprentice(object me)
{
    if(me->query("m_success/��ƽ���ַ粨") && me->query("combat_exp")>1000000){
                command("say ������Ϊ���ֳ�һ�󺦵ķ��ϣ��Ҿ�����Ϊͽ�ɣ�\n");
        command("recruit " + me->query("id") );
    } else {
                command("sigh");
        command("say ���Ѿ������ǰ����ˣ����������ˣ���ֻ�ǵ�һ��ؤ��ľ������㻹��ȥ���Ϲ��ɣ�\n");
    }
} 
void recruit_apprentice(object ob){
    if( ::recruit_apprentice(ob) )
        ob->set("class", "beggar");
} 
int kill_him(){
    command("say �Ϲ�������ΪТ˳��ÿ������һ�룬��δ��ϣ�\n");
    return 1;
} 
int chuanren(){
        object me, con, ob;
        string rank;
        me = this_player();
        if(!environment(this_object())->query("have_staff")){
           message_vision("$Nҡҡͷ������ؤ�����д��ˡ���\n", this_object());
                return 1;
        }
    rank = me->query("family/title");
    if(me->query("class") != "beggar"){ 
                message_vision("$Nҡ��ҡͷ�����������ؤ����ӣ��޷���Ϊؤ�ﴫ�ˡ���\n", this_object());
    } else if(rank == WHT"�Ŵ�����"NOR || rank == WHT"����"NOR
            || rank == HIW"��ͷ���"NOR){
                message_vision("$N�����˫ĿͻȻ�����������������ε��������Ը����������У�����Ӯ��������Ϲ�ͷ��
�ǲš����� �����������壩\n", this_object());
                add_action("do_challenge", "challenge");        
        } else {
                message_vision("$Nǿ���Ӵ�����������������$n���˰���̾�˿�����ҡ��ҡͷ��\n", this_object(), me); 
        }
        return 1;
} 
int do_challenge(){
        object me, ob;
        int i;
        me = this_player();
        
        delete_temp("last_damage_from");
        message_vision("\n$N���������С���������\n", this_object());
        for(i=0; i<10; i++) {
                 COMBAT_D->do_attack(me,this_object(),me->query_temp("weapon"));
            if(query_temp("last_damage_from") == me) {
                    break;
            }
        }
        if(query_temp("last_damage_from") == me) {
                message_vision("$N�����ݺ�������úã������ҵ�����֮���ˣ�ؤ���о��ˡ������� \n", this_object());
                ob = new(__DIR__"obj/zhustaff");
                if(objectp(ob)){
                        message_vision("$N��ΡΡ����$nһ���򹷹�����Ȼ���������´򹷹���ؤ�︴����ǧ���ص��͸����ˡ�����\n",
                                        this_object(), me); 
                        ob->move(me);
            me->set("title", "ؤ�� ���ߴ�����");
                        environment(this_object())->set("have_staff", 0);
                }
        } else {
   message_vision("$Nҡͷ̾�˿�����\n", this_object());
        }
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
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "beggar"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N��ΡΡ�ص������Ϸ�Ķ��������Ϸ����ƴ�������һ����Ҳ��������óѣ�\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 
int leave() {
        if (this_player()->query("class")!="beggar") return 0;
        message_vision(CYN"$N̾�˿���������ؤ��ûָ���ˡ���\n"NOR, this_object());
        message_vision(CYN"$N˵���򹷰����ͻ���ľ�����ʦү�������ģ������˾�ѧ�����ˡ�\n"NOR,this_object());
        return 1;
}     
