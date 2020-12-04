 // yangfan.c
//inherit F_LEADER;
inherit NPC; 
inherit F_MASTER; 
#include <ansi.h>
void create()
{
        set_name("�", ({ "yang fan", "yang"}) );
        set("gender", "����" );
        set("age", 28);
        set("title","ɽ�� ����");
        set("nickname",HIY"��ͷ"NOR);
        set("class","shaolin");
        set("reward_npc", 1);
        set("difficulty", 15);
        set("long",
"���Ǹ��������ֵ������ˣ�ԲԲ������һ˫�۾�ȴ��ϸ�ֳ�����ܴ�ͷ���󣬿�����
�е�����˽䡣����������ȴ�ܴ����򶨣���������˵���е����������ӡ�\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            "�գ��գ�ۣ��ֺǺǺ���С������ͷ��ͷ�����겻�������ɡ�����д�ͷ��\n",
    }) );
        set("inquiry",  ([
                "ɽ��" : "ɽ��ֻ��һȺ��ƽ�����ˣ���ȴ��Ϊ��һ����ƽ������������ڡ�\n",
                "shanliu" : "ɽ��ֻ��һȺ��ƽ�����ˣ���ȴ��Ϊ��һ����ƽ������������ڡ�\n",
                "Ѫ��ϭ": "Ѫ��ϭ���˽Գư�һ���ĺڵ����ɣ�����С�ӡ�\n",
                "questnpc": "Ѫ��ϭ���˽Գư�һ���ĺڵ����ɣ�����С�ӡ�\n",
                ])                      ); 
        set("combat_exp", 80000000);
        set("attitude", "friendly");
        set("per",1);
        set("str", 100);
        set("force",50000);
        set("max_neili",50000);
        set("force_factor",150);
        set("org_ranks",({
"��ʿ","����","����ʹ��","ƽ������" })); 
	set_skill("literate", 100);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);

	set_skill("construction", 380);
	set_skill("painting", 380);


	        set_skill("songshan-sword", 380);
        set_skill("songshan-jian", 380);
        set_skill("songshan-qigong", 380);
        set_skill("dodge", 290);
        set_skill("zhongyuefeng", 380);
        set_skill("strike", 290);
        //set_skill("songyang-zhang", 380);
        set_skill("hanbing-zhenqi", 380);
        set_skill("parry", 290);
        set_skill("sword", 290);
        set_skill("songshan-jian", 380);
        //set_skill("songyang-zhang", 380);
        //set_skill("songyang-shou", 380);
        set_skill("literate", 250);
        set_skill("hanbing-shenzhang", 380);
		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	set_skill("songshan-sword", 380);
	set_skill("songyang-strike", 380);
	set_skill("poyun-hand", 380);
	set_skill("hanbing-zhenqi", 380);
	set_skill("fuguanglueying", 380);
	map_skill("strike", "songyang-strike");
	map_skill("hand", "poyun-hand");
	map_skill("sword", "songshan-sword");
	map_skill("parry", "songshan-sword");
	map_skill("dodge", "fuguanglueying");
	map_skill("force", "hanbing-zhenqi");
	prepare_skill("strike", "songyang-strike");
	prepare_skill("hand", "poyun-hand");

	set("no_get",1);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: command("haha") :),
//		(: command("unwield sword") :),
//		(: command("wield sword") :),
		(: perform_action, "sword.feiwu" :),
		(: perform_action, "sword.jianqi" :),
		(: perform_action, "sword.suiyuan" :),
		(: perform_action, "strike.yinyang" :),
		(: perform_action, "strike.junji" :),	
		(: perform_action, "hand.chanyun" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
        
}  
void init()
{
        object ob;
        ::init();
        if( userp(ob = this_player()))
        if(ob->query_temp("ɽ��/������"))
        {
                remove_call_out("greeting");
                call_out("greeting", 30, ob);
        }
        add_action("do_kill","kill");
        add_action("do_answer","answer");
} 
void greeting(object me)
{
        if(!me ||environment(me)!=environment())
                return ;
        if(!living(me))
                me->revive();
        message_vision(CYN"$N������˫�ֳ���ϸ���۾�����$nЦ��Ц˵�����ֹ�Ȼ��ͬ�����ˡ�\n"NOR,this_object(),me);
        message_vision(CYN"$NͻȻ��ɫ��Ȼ��֣�صض�$n˵���ã������Ը��ɽ������Ȼ��ӭ���롺ɽ������\n��join yang fan����\n"NOR,this_object(),me);
        return ;
}  
void accept_member(object me)
{
        command("smile");
        command("enroll "+me->query("id"));
        message_vision(HIC"$N����Ƭ������Ȼ�������������������ڹ��ᣬ��ͼ�������ºڵ��������ڵ�����
�޲��յ��䡺��������������뽫��Ѫ��ϭ����questnpc���и������۵��������֮��
���ظ��֣��¹ؽ���������˥����������С�����£�\n"NOR,this_object(),me);
        me->delete("��ɽ��");
        me->delete_temp("ɽ��");
        me->set("organization/org_name","ɽ��");
        me->set("organization/org_level",0);
        me->set("organization/����","��");
        CHANNEL_D->do_sys_channel("info",sprintf("%s��ĳ�����ܼ�����������֯%s��",NATURE_D->game_time(),me->query("organization/org_name")) );
        me->save();
} 
void attempt_join(object me)
{
        if(me->query_temp("ɽ��/������"))
           accept_member(me);
        else
                message_vision("�ϸüһ�壬��������֣��������ð�����ġ�\n",this_object());
}  
int do_kill(string arg)
{
        object me; 
        me=this_player();
        if(!arg) return 0;
        if(this_object()==present(arg,environment()))
                me->set("ɽ��/ʧ��",time());
        return 0;
} 
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        if ( me->query_temp("����/׼��ɱ�") ) 
        	me->set("����/������",1);
        ::die();
}  

