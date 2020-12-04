//by xiaolang
inherit NPC;
#include <ansi.h> 
int test_dart();
void create_level(object who,string name, int exp); 
void create()
{
    set_name("����", ({ "huo xiu" }) );
    set("gender", "����" );
    set("age", 32);
    set("neili",500);
    set("title","����");
    set("force_factor",20);
    set("max_neili",500);    
    set("inquiry",      ([
        "mission" : (: test_dart :),
        ]) );
    set("int", 30);
    set("long",
        "��һ����ϴ�ķ��׵��������ѣ���Ŵ���˫�Ʋ�Ь�������ڵ�����ֻ\n�������ں���С��¯���¾ơ�\n"
        );
	set("neili", 22400);
	set("max_neili", 22400);
	set("max_qi", 22000);
	set("max_jing", 21200);
	set("combat_exp", 8000000);
	set("shen_type", 1);

	set_skill("strike", 150);
	set_skill("kuaihuo-strike", 310);
	set_skill("sword", 350);
	set_skill("taishan-sword", 320);
	set_skill("shiba-pan", 320);
	set_skill("force", 150);
	set_skill("panshi-shengong", 350);
	set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("fengshenjue", 310);
	set_skill("dramaturgy", 380);
	set_skill("horticulture", 380);
	map_skill("sword", "taishan-sword");
	map_skill("parry", "taishan-sword");
	map_skill("dodge", "fengshenjue");
	map_skill("force", "panshi-shengong");
	map_skill("strike", "kuaihuo-strike");
	prepare_skill("strike", "kuaihuo-strike");
	set("no_get",1);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.heru" :),
		(: perform_action, "sword.ruhe" :),
		(: perform_action, "sword.wuyue" :),
		(: perform_action, "sword.18pan" :),
		(: perform_action, "strike.zhouyu" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );    
    set("combat_exp", 35000000);
    setup();
    carry_object(__DIR__"obj/hxcloth")->wear();
    carry_object(__DIR__"obj/hxshoes")->wear();
} 
void init()
{
        ::init();
//        add_action("do_accept", "accept");
} 
int test_dart()
{
    object me;
        
    me=this_player();
    if(me->query("organization/����") != "а")
    {
    	command("say �㲻��������֯�ģ�����ô�����㣿\n");
    	return 1;
    }

    if(me->query("����ʧ��/timer")+180>time())
    {
    	command("say ��ջ���ʧ�ܲ��á�\n");
    	return 1;
    }
    if(me->query("improbity")>= 100)
    {
    	command("say ���Ѿ����ĺܲ����ˣ��ɵ�����ȥ�ɡ�\n");
    	return 1;
    }
    	
    if (query("��������/gived") )
    {
        set("��������/gived",1);
        command("say �������ﻹû����Ҫ�Ļ�������");
        return 1;
    }
    command("say ������һ����Ҫ������ҪȥĿ�ĵأ����Ƿ�Ը�⣿(accept mission)");
//    add_action("do_accept","accept");
    return 1;
} 
int do_accept(string arg)
{    
    object ob,cart,biaotou;
    object me,*team;
    string location,msg;
    int i, exp,n; 
    
    msg="";
    if (arg != "mission") return 0;
    me=this_player();
    team=me->query_team();
    if (sizeof(team)==0) team=({me}); 
   if (sizeof(team) != 0 && (team[0]!=me)) 
        return notify_fail("say ֻ�ж���������������������\n");
    for (i=0;i<sizeof(team);i++)
    {
    	if(team[i]->query("����ʧ��/timer")+180>time())
    		return notify_fail("����鵱�����˸ջ���ʧ�ܲ��á�\n");
    	}
    	
    for (i=0;i<sizeof(team);i++)
    {
//    	team[i]->set_temp("��������/�Ѷ�",1);
        if (team[i]->query("combat_exp")<15000000)
        {
            command("say ����·;Σ�գ��ҿ���λ"+RANK_D->query_respect(team[i])+"�ƺ����ˣ�");
            return 1;
        }
/*        if (!intp(team[i]->query("deposit")) || team[i]->query("deposit")<1000000)
        {
            command("say ������Σ�յ��£��ҿ�"+RANK_D->query_respect(team[i])+"û���⳥������");
            return 1;
        }  */
        if(team[i]->query("organization/����") != "а"){
        	command("heng");
        	command("say �ѵ�����������Ҫ������������Ե����ɣ�\n");
        	return 1;        	
        }
        if(team[i]->query("improbity") >= 100){
        	command("smile");
        	command("say ��������Ѿ��������ĺܲ����ˣ�����Ҫ���������ˣ������ɵ���ȥ�ɡ�\n");
        	return 1;
        }
        
        if (team[i]->query("combat_exp")>exp)
                exp= team[i]->query("combat_exp");
    } 
    

        if (query("��������/gived"))
                {
                 command("say �������ˣ��Ѿ����˽�����������ˡ�");
                 return 1;
                }

    set("��������/gived",1);
    command("say һ·С�ġ�");
    location = environment(me)->query("short");        
    biaotou=new("/obj/npc/importman");
    biaotou->move(environment());
    n=random(3);
    switch( n ) {
    	case 0:
    		biaotou->get_quest("/d/taishan/way/way1_ts_to_lyz");
    		msg = "ǰ������կ";
    		break;
    	case 1:
    		biaotou->get_quest("/d/taishan/way/way2_ts_to_qp");
    		msg = "ǰ����ƽɽׯ";
    		break;
    	case 2:
    		biaotou->get_quest("/d/taishan/way/way3_ts_to_fy");
    		msg = "ǰ�����Ƴǽ�Ǯ��";
    		break;
    }
    for (i=0;i<sizeof(team);i++)
    {
    	team[i]->set_temp("��������/�Ѷ�",n+1);
    }		
    biaotou->set_protector(team);
    biaotou->set("combat_exp",exp*3/5);
    create_level(biaotou,"importman",exp*3/5);
    
    CHANNEL_D->do_sys_channel(
                "info",sprintf("%s��%s����һ����Ҫ�����%s����%s��", NATURE_D->game_time(),
                me->query("name"),location,msg) );     

    me->set_leader(biaotou);
    me->set_temp("��������/accepted",1);
    biaotou->go_now();
    return 1;   
} 
void reset()
{
    delete("��������/gived");
}  
void create_level(object who,string name, int exp)
{
        int level;
        level=100+130*(exp-1000000)/6500000;
        if (exp<1000000) level=100;
        if (exp>7500000) level=200;
        level=level*level/100;
        if (name=="importman") {
                
                who->command("say �Ҿ����Ǹ�������Ա��·�϶���չˡ�");
                who->set("str",10+random(level/15));
                who->set("agi",10+random(level/8));
           	who->set("cor",20+random(15));
//                who->set("max_qi",1000+random(level*level/20));
//                who->set("eff_qi",who->query("max_qi"));
//                who->set("qi",who->query("max_qi"));
                who->set_skill("blade", 100 + random(level*2/3));
                who->set_skill("parry", 100 + random(level*2/3));
                who->set_skill("dodge", 100 + random(level*2/3));
                who->set_skill("demon-steps",100+random(level*2/3));
                who->set_skill("move", 100 + random(level*2/3));
                who->set_skill("moon-blade",100+random(level*2/3));
                who->set_skill("unarmed",100 + random(level*2/3));
        }
        if (name=="killer") {
                who->set("str",10+random(level/12));
                who->set("agi",10+random(level/8));
                who->set("cor",20+random(15));
                who->set("max_qi",2500+random(level*level/40));
                who->set("eff_qi",who->query("max_qi"));
                who->set("qi",who->query("max_qi"));
                who->set("max_sen",who->query("max_qi")/2);
                who->set("max_jing",who->query("max_qi")/2);
                who->set("eff_sen",who->query("max_sen"));
                who->set("sen",who->query("max_sen"));
                who->set("eff_jing",who->query("max_jing"));
                who->set("jing",who->query("max_jing"));
                who->set_skill("parry", 70 + random(level/2));
                who->set_skill("dodge", 70 + random(level/2));
                who->set_skill("move", 70 + random(level/2));
                who->set_skill("blade",70+random(level/2));
                who->set_skill("fall-steps",70+random(level/2));
                who->set_skill("unarmed",70+ random(level/2));
                who->set_skill("yue-strike",50+random(level/8));
                who->set_skill("shortsong-blade",50+random(level/8));
        } 
}   
