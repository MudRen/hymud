 // taolord.c
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int leave(); 
void create()
{
    set_name("ʯ��", ({ "master shi", "master", "shi" }) );
    set("nickname", "��������");
    set("gender", "����");
    set("age", 62);
    set("long",
        "ʯ���˵����䵱���ţ�����̫���ķ������Ž����������˼��ߵľ��硣\n"
        "�����侫̫ͨ�����У����������ǵ�����˫�������˳ƣ��������ˣݡ�\n");
    set("combat_exp", 90000000);
    set("score", random (20000)); 
    set("class", "wudang");
    set("reward_npc", 1);
    set("difficulty", 40); 
    set("int", 30);
    set("cor", 20);
    set("cps", 30);
    set("spi", 30);
    set("fly_target",1);        
    
        
    set("inquiry", ([
        "̫���ķ�": "̫���ķ��˵������ŵĻ����ķ����ܹ��������ڵ�����������\n",
        "�䵱��":   "���䵱���������˿�ɽ����������������������������Ϊ���Ρ�\n",
        "���Ƿ�" :  "���Ƿ���Ϊ����ȴֻ�����������Ǿ���hanxing���ͻ��Ǿ���jixing����\n",
        "qixing" :  "���Ƿ���Ϊ����ȴֻ�����������Ǿ���hanxing���ͻ��Ǿ���jixing����\n",
    "leave" : (: leave :),
         ]) ); 
set("qi", 28000);
	set("max_qi", 28000);
	set("jing", 28000);
	set("max_jing", 28000);
	set("neili", 55000);
	set("max_neili", 55000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 600000);
	set("shen", 200000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
    create_family("�䵱��", 57, "������");
    set("rank_nogen",1);
    set("ranks",({"��ʿ","С����","����","С��ʦ","��ʦ",YEL"����ʦ"NOR,YEL"������"NOR,
                      HIY"����"NOR})); 
  
    setup(); 
    carry_object(__DIR__"obj/msword")->wield();
    carry_object(__DIR__"obj/mcloth")->wear();
    carry_object(__DIR__"obj/mhat")->wear();
} 

int accept_object(object who, object ob)
{
    object              book; 
    if((string)ob->name() != "���Ʒɵ��غ�") return 0;
    command("say ��л��λ" + RANK_D->query_respect(who));
    command("say �Ȿ������������ɡ�");
    book = new(__DIR__"obj/wubook");
    book->move(this_object());
    command("give book to " + who->get_id());
    return 1;
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
void greeting(object ob)
{
        object *inv,letter, *sy_inv, things;
        int i,j;
        int got_sword = 0;
        if( !ob || environment(ob) != environment() ) return;
        
/*        if (ob->query("once_menpai/shaolin") && !ob->query("marks/muren_time")
                && !ob->query("marks/bugout") && ob->query("class")=="wudang"
                && ob->query("betrayer")==0)
        {
                ob->set("marks/bugout",1);
                letter = new(__DIR__"obj/letter1");
           if(letter) letter->move(ob);
                message_vision(HIW"ž��һ����$N�ӻ����ͳ�һ��������$n���\n"NOR,this_object(),ob);
                message_vision(HIW"$N˵���Լ�ȥ���ɡ�\n"NOR,this_object());
                ob->add("betrayer",1);
        } */
        if(ob->short() == "�䵱������(wudang master)") {
//Okey, we got a old wudang master here, fake or real?
        inv =all_inventory(ob);
        for(i=0; i<sizeof(inv); i++) 
         if(inv[i]->query("fake_7sword") && inv[i]->query("equipped")=="wielded"
                && inv[i]->query_temp("marks/owner_name") == ob->query("id")) 
                got_sword = 1;
        if(got_sword) {
        for(i=0; i<sizeof(inv); i++)
        if(inv[i]->query("name")=="���") destruct(inv[i]);
        command("say ���ģ��⣬�⣬���ǣ��ǣ��ϣ��ϰ���ô��\n");
        message_vision("$NͻȻһ����Ѫ���˳��������ŵ�������ϣ���ɫ���ڡ�����һͷ�Ե��ڵ��¡�\n",
        this_object());
        ob->set_temp("killed_master_shi",1);
        
        sy_inv = all_inventory(this_object());
        for(j=0;j<sizeof(sy_inv);j++){
                things = sy_inv[j];
                destruct(things);
        }
        this_object()->die();
        tell_object(ob,"���ڿ���ȥ֪ͨ�ϵ������ˣ������˴��Ͼ�����ǰ��潣��\n");
        
        } else {
        command("say �󵨣����һ�ױ���ϰ������Ż��Ϸ�\n");
        kill_ob(ob);
        } 
        }
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
        if(id_class == "wudang"&& userp(victim)&&player!=victim)
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
        if (this_player()->query("class")!="wudang") return 0;
        message_vision(CYN"$Nŭ�����������ļһ���ҹ�����\n"NOR, this_object(),this_player());
        message_vision(CYN"$N˵�����߿��ԣ���̫�����е��䵱�ؼ���ͱ��������ˡ�\n"NOR,this_object(),this_player());
        message_vision(CYN"$N˵���Ժ�Ҳ���������ң�\n"NOR,this_object(),this_player());
        return 1;
}
