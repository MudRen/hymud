// sz,npc:shenyi
// 97.10.1 by Aug

inherit NPC;
inherit F_MASTER;

#include <ansi.h>

int give_zhen();
int heal_other();
string ask_liwu15();
int last_time=-100000;

void create()
{
	set_name("Ҷ����", ({ "ye yishi","ye" }) );
	set("title", "�������ҵ��ߴ�����");
	set("nickname","��������"); 
	set("gender", "����");
	set("age", 61);

	set("long","Ҷ�����Ǹ��������ݣ�������ˬ���������٣���Ȼ��������ˡ�\n");
	set("rank_info/respect", "��ҽ");

	set("eff_jing", 9000);
	set("eff_qi", 9000);
	set("jing", 9000);
	set("qi", 9000);

	set("max_jing", 9000);
	set("max_qi", 9000);

	set("max_neili", 53000);
	set("eff_neili", 53000);
	set("neili", 53000);

	set("str", 15);
	set("cor", 35);
	set("cps", 35);
	set("spi", 35);
	set("int", 100);
	set("con", 40);
	set("kar", 50);
	set("per", 35);

	set("combat_exp", 6000000);
	set("score",100000);

	set_temp("no_kill", 1);
	set_skill("force", 400);
	set_skill("parry", 400);
	set_skill("dodge", 400);
	set_skill("throwing",400);
	set_skill("literate", 400);
	set_skill("unarmed", 400);

	set_skill("miaoshouhuichun",500);
	
	map_skill("throwing",  "miaoshouhuichun");

	set("inquiry", ([
		"����" : (: give_zhen :),
		"����" : (: heal_other :),
		"�ⶾ" : (: heal_other :),
		"jiedu" : (: heal_other :),
		"heal" : (: heal_other :),
		"���" : (: heal_other :),
		"zhenjiu" : (: heal_other :),
	"job" : (: ask_liwu15 :),
	]) );	

	
	

	setup();

	add_money("gold", 1);	
	carry_object(__DIR__"obj/changshan")->wear();
	carry_object(__DIR__"obj/yinzhen")->wield();
}

void init()
{       
	object ob;

	::init();
	if( interactive(ob = this_player()) ) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

	add_action("do_xue","xue");
	add_action("do_xue","learn");
}

void greeting(object ob)
{
	if( living(this_object()) ==0 ) return;

	if( !ob || environment(ob) != environment() ) return;

		command("say ��������������͹��ٺ����ǲ���Ҫҽ��ʲô��������"); 

}

int accept_fight(object ob)
{
	return notify_fail(CYN"Ҷ��ҽ˵���������ˣ�û�����������ˡ�\n"NOR);  
}

int give_zhen()
{
	object ob;

	ob=this_player();

// һ��plÿСʱֻ���õ�һö����
	if (ob->query("last_getzhen")
		&& (ob->query("mud_age")-ob->query("last_getzhen"))<(1*60*60) )
	{
		command("say "+ob->query("name")+"���㲻�Ǹ����ù���������ô�����ˣ�");
		return 1;
	}



// 1 ����/ 3 min
	//if( (time() - last_time) < (3*60) )
	//{
	//	command("say �Բ����ҵ����붼�����ˣ����һ������������ɡ�");
	//	return 1;
	//}
	
	if ( ob->over_encumbranced() )   
	{
		write("���Ѿ����ɹ����ˣ�\n");
		return 1;
	}

	if ( present( "yinzhen" , ob) ) 
	{
		command("say �����ϲ��ǻ������ô������Ҫ�ˣ�\n");
		return 1;
	}

	last_time=time();	
	ob->set("last_getzhen",ob->query("mud_age"));

	new(__DIR__"obj/yinzhen")->move(ob);
        ob->set_temp("yinzhen", 0);

	message_vision("Ҷ��ҽ����$Nһ�����룬˵�������Ҫ�ú�������ö�������밡��\n",ob);

	return 1;
}

int heal_other()
{
	object me,ob,ob2;

	ob=this_player();
	me=this_object();


if (ob->is_busy())
	{
		command("say ������æ��\n");
		return 1;
	}
if (ob->is_fighting())
	{
		command("say ������æ��\n");
		return 1;
	}


	if(ob->query("zhuanshen")  )
	{
		command("say ����ôǿ��Ӧ���Լ��չ��Լ��ˣ�\n");
		command("say ���߰ɣ�");
		return 1;
	}



	if(me->query("neili")<50 || me->query("jing")<30)
	{
		//command("say ���������ˣ�������������ɡ�\n");
		//return 1;
	}

	if(!present( "yinzhen" , me))
	{
		ob2=new(__DIR__"obj/yinzhen");
		ob2->move(me);
		command("wield zhen");		
	}
	
	command("say �ã��͸��������˰ɡ�");
	//command("zhenjiu "+ob->query("id"));
	ob->set("qi",ob->query("max_qi"));
	ob->set("eff_qi",ob->query("max_qi"));
	ob->set("jing",ob->query("max_jing"));
	ob->set("eff_jing",ob->query("max_jing"));

if (ob->query_condition("ill_fashao"))
	ob->clear_condition("ill_fashao");

if (ob->query_condition("ill_kesou"))
	ob->clear_condition("ill_kesou");

if (ob->query_condition("ill_shanghan"))
	ob->clear_condition("ill_shanghan");

if (ob->query_condition("ill_zhongshu"))
	ob->clear_condition("ill_zhongshu");

if (ob->query_condition("ill_dongshang"))
	ob->clear_condition("ill_dongshang");
	
		if (ob->query_condition("scorpion_poison"))
        ob->clear_condition("scorpion_poison");
		if (ob->query_condition("ss_poison"))
        ob->clear_condition("ss_poison");
		if (ob->query_condition("tmzhuihun_poison"))
	ob->clear_condition("tmzhuihun_poison");
		if (ob->query_condition("tmpili_poison"))
        ob->clear_condition("tmpili_poison");

		if (ob->query_condition("zimu-zhen"))
        ob->clear_condition("zimu-zhen");




		if (ob->query_condition("zm_poison"))
        ob->clear_condition("zm_poison");
		if (ob->query_condition("drunk"))
			ob->clear_condition("drunk");
		if (ob->query_condition("flower_poison"))
			ob->clear_condition("flower_poison");
		if (ob->query_condition("ice_poison"))
			ob->clear_condition("ice_poison");
		if (ob->query_condition("iceshock"))
			ob->clear_condition("iceshock");
		if (ob->query_condition("rose_poison"))
			ob->clear_condition("rose_poison");
		if (ob->query_condition("sanxiao_poison"))
			ob->clear_condition("sanxiao_poison");
		if (ob->query_condition("scorpion_poison"))
			ob->clear_condition("scorpion_poison");
		if (ob->query_condition("slumber_drug"))
			ob->clear_condition("slumber_drug");
		if (ob->query_condition("snake_poison"))
			ob->clear_condition("snake_poison");
		if (ob->query_condition("ss_poison"))
			ob->clear_condition("ss_poison");
		if (ob->query_condition("xx_poison"))
			ob->clear_condition("xx_poison");
		if (ob->query_condition("zhua_poison"))
			ob->clear_condition("zhua_poison");
        if (ob->query_condition("snake_poison"))
        {          ob->clear_condition("snake_poison");}
        if (ob->query_condition("wugong_poison"))
        {          ob->clear_condition("wugong_poison");}
        if (ob->query_condition("zhizhu_poison"))
        {          ob->clear_condition("zhizhu_poison");}
        if (ob->query_condition("xiezi_poison"))
        {          ob->clear_condition("xiezi_poison");}
        if (ob->query_condition("chanchu_poison"))
        {          ob->clear_condition("chanchu_poison");}
        if (ob->query_condition("qishang_poison"))
        {          ob->clear_condition("qishang_poison");}
        if (ob->query_condition("jy-poison"))
        {          ob->clear_condition("jy-poison");}
        if (ob->query_condition("xx_poison"))
        {          ob->clear_condition("xx_poison");}
        if (ob->query_condition("cold_poison"))
        {          ob->clear_condition("cold_poison");}
        if (ob->query_condition("flower_poison"))
        {          ob->clear_condition("flower_poison");}
        if (ob->query_condition("chilian_poison"))
        {          ob->clear_condition("chilian_poison");}
        if (ob->query_condition("yufeng_poison"))
        {          ob->clear_condition("yufeng_poison");}
        if (ob->query_condition("anqi_poison"))
        {          ob->clear_condition("anqi_poison");}
       if (ob->query_condition("yf_poison"))
        {          ob->clear_condition("yf_poison");}
       if (ob->query_condition("nx_poison"))
        {          ob->clear_condition("nx_poison");}
       if (ob->query_condition("x2_poison"))
        {          ob->clear_condition("x2_poison");}
       if (ob->query_condition("sanpoison"))
        {          ob->clear_condition("sanpoison");}
       
       if (ob->query_condition("insect_poison"))
        {          ob->clear_condition("insect_poison");}
	
	if (ob->query_condition("zm_poison"))
		ob->clear_condition("zm_poison");
	
	if (ob->query_condition("tmpili_poison"))
		ob->clear_condition("tmpili_poison");
	
	if (ob->query_condition("tmzhuihun_poison"))
		ob->clear_condition("tmzhuihun_poison");
        
        if (ob->query_condition("snake_poison"))
        {          ob->clear_condition("snake_poison");}
        
        if (ob->query_condition("wugong_poison"))
        {          ob->clear_condition("wugong_poison");}
        
        if (ob->query_condition("zhizhu_poison"))
        {          ob->clear_condition("zhizhu_poison");}
        if (ob->query_condition("xiezi_poison"))
        
        {          ob->clear_condition("xiezi_poison");}
        
        if (ob->query_condition("chanchu_poison"))
        {          ob->clear_condition("chanchu_poison");}

ob->clear_condition("anqi_poison");
ob->clear_condition("baituo_poison");
ob->clear_condition("bat");
ob->clear_condition("bing_poison");
ob->clear_condition("binghuo");
ob->clear_condition("black_poison");
ob->clear_condition("broken_arm");
ob->clear_condition("canxia");
ob->clear_condition("chanchu_poison");
ob->clear_condition("chilian_poison");
ob->clear_condition("cold_poison");
ob->clear_condition("corpse_poison");
ob->clear_condition("cuixin_zhang");
ob->clear_condition("dashouyin");
ob->clear_condition("dragon_poison");
ob->clear_condition("emerald_poison");
ob->clear_condition("fire_poison");
ob->clear_condition("flower_poison");
ob->clear_condition("green_blood");
ob->clear_condition("hehe");
ob->clear_condition("hot_poison");
ob->clear_condition("huanyin_poison");
ob->clear_condition("ice_poison");
ob->clear_condition("iceshock");
ob->clear_condition("ill_dongshang");
ob->clear_condition("ill_fashao");
ob->clear_condition("ill_keshou");
ob->clear_condition("ill_kesou");
ob->clear_condition("ill_shanghan");
ob->clear_condition("ill_zhongshu");
ob->clear_condition("insect_poison");
ob->clear_condition("juehu_hurt");
ob->clear_condition("jy-poison");
ob->clear_condition("jy_poison");
ob->clear_condition("libie");
ob->clear_condition("new_poison1");
ob->clear_condition("new_poison2");
ob->clear_condition("new_poison3");
ob->clear_condition("new_poison4");
ob->clear_condition("new_poison5");
ob->clear_condition("new_poison6");
ob->clear_condition("new_poison7");
ob->clear_condition("new_poison8");
ob->clear_condition("no_shadow");
ob->clear_condition("nx_poison");
ob->clear_condition("poison");
ob->clear_condition("poison_sandu");
ob->clear_condition("qiankun_wound");
ob->clear_condition("qiankunyibang");
ob->clear_condition("qinghua_poison");
ob->clear_condition("qishang_poison");
ob->clear_condition("qx_snake_poison");
ob->clear_condition("rose_poison");
ob->clear_condition("sanpoison");
ob->clear_condition("sanxiao_poison");
ob->clear_condition("scorpion_poison");
ob->clear_condition("shenlong_poison");
ob->clear_condition("shenzhao");
ob->clear_condition("sl_poison");
ob->clear_condition("snake_poison");
ob->clear_condition("ss_poison");
ob->clear_condition("tiezhang_yang");
ob->clear_condition("tiezhang_yin");
ob->clear_condition("tmpili_poison");
ob->clear_condition("tmqidu_poison");
ob->clear_condition("tmzhuihun_poison");
ob->clear_condition("unknown");
ob->clear_condition("wudoumi-fanshi");
ob->clear_condition("wugong_poison");
ob->clear_condition("wuhudu_poison");
ob->clear_condition("wuxing_poison");
ob->clear_condition("x2_poison");
ob->clear_condition("x2_sandu");
ob->clear_condition("xiezi_poison");
ob->clear_condition("xscold_poison");
ob->clear_condition("xuanming_poison");
ob->clear_condition("xuantian_han");
ob->clear_condition("xx_condition");
ob->clear_condition("xx_liandu");
ob->clear_condition("xx_poison");
ob->clear_condition("xx_sandu");
ob->clear_condition("yf_poison");
ob->clear_condition("yufeng_poison");
ob->clear_condition("yyz_damage");
ob->clear_condition("zhizhu_poison");
ob->clear_condition("zhua_poison");
ob->clear_condition("zimu-zhen");
ob->clear_condition("zm_poison");
ob->clear_condition("zmqidu_poison");


  
        ob->start_busy(5);
	return 1;
}

int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_time"))      
		who->set_temp("learn_time", 0);

/*
	if( who->query("shen") < 0 ) 
	{
		command("say ���˱����������ѧ����ѧ��");
		command("say ������ô������ģ����ҹ���");
		who->move("/d/pingan/west2");
		return 1;		
	}

	if( !ob->query("money_id") )
	{
		command("say �⣬�⣬�Ϸ�Ͳ������ˡ�");
		return 1;		
	}
*/

//	if( who->query("shen") < 0 ) 
//		return 0;		

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("miaoshouhuichun",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("miaoshouhuichun",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("miaoshouhuichun",1)<100)
				i=ob->value() / 200;
			else
				i=ob->value() / 500;
		}
	}
	who->add_temp("learn_time",i);

      message_vision("Ҷ��ҽ��$N˵������Ȼ�������ѧҽ���Ҿͳ�ȫ��ȫ��ɡ�\n",who);
      tell_object(who,"�����������Ҷ��ҽѧϰ(xue ye miaoshouhuichun)�ˡ�\n");

	return 1;
}

int do_xue(string arg)
{
	object me,ob;
	string skill,teacher;
	int jing_cost,my_skill,intx;

	me=this_player();
	ob=this_object();

	if( living(me) ==0 ) return 0;

	if (me->is_busy())
	{
		tell_object(me,"��������æ���ء�\n");
		return 1;
	}

	if(!arg || (sscanf(arg, "%s %s", teacher, skill)!=2 ))
	{
		tell_object(me,"ָ���ʽ��learn|xue <ĳ��> <����>\n");
		return 1;
	}

	if( ob != present(teacher, environment(me)) )
	{
		tell_object(me,"��Ҫ��˭��̣�\n");
		return 1;
	}

	if( !living(ob) )
	{
		tell_object(me,"��....����Ȱ�" + ob->name() + "Ū����˵��\n");
		return 1;
	}

	if( me->is_fighting() )
	{
		tell_object(me,"����ĥǹ������������\n");
		return 1;
	}

	if( skill!="miaoshouhuichun" )
	{
		tell_object(me,CYN"Ҷ��ҽ˵�������Ź��������Ҫ�����ȥѧ�ˡ�\n"NOR);
		return 1;
	}

	message_vision("$N��$n����йء����ֻش��������ʡ�\n",me,ob);

	if( me->query_temp("learn_time") <= 0)
	{
		command("say ���ֻش��ɲ�����ô����ѧ�ģ����Ҫ�к��İ���");
		return 1;
	}

	my_skill=me->query_skill("miaoshouhuichun",1);

	if(  my_skill>=200 )
	{
		command("say ���Ѿ���ȫ���������ֻش������У���Ҳûʲô�����ٽ̸����ˡ�");
		return 1;
	}

	if( (int)me->query("learned_points") >= (int)me->query("potential") )
	{
		tell_object(me,"���Ǳ���Ѿ����ӵ������ˣ�û�а취�ٳɳ��ˡ�\n");
		return 1;
	}

	jing_cost = 300 / (int)me->query("int");

	if(jing_cost > (int)me->query("jing") )
	{
		tell_object(me,"��̫���ˣ����ʲôҲûѧ����\n");
		me->set("jing",0);
		return 1;
	}

	me->add_temp("learn_time",-1);
	me->add("learned_points", 1);
	if (me->query("zhuanshen"))  me->add("jing", -jing_cost);
	
	if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
	{
		tell_object(me,"Ҳ����ȱ��ʵս���飬���"+ob->name()+"�Ļش������޷���ᡣ\n");
		return 1;
	}

	if( !my_skill ) 
	{
		me->set_skill(skill,0);
	}

	message_vision("$N����$n��ָ�����ƺ���Щ�ĵá�\n",me,ob);
intx=(int)me->query_int();
if ((!me->query("zhuanshen") && !me->query("guard/flag") && !me->query("zhuanbest") && !me->query("4zhuan") && !me->query("5zhuan")) || me->query("hyvip")==4) intx=intx*2+5;

	me->improve_skill(skill, random(intx));

	return 1;
}

string ask_liwu15()
{
  string msg;
  object ob1;
  object me=this_player();
  int exp_bound,qn_bound,neili;
  me->set_temp("nbjob21",1);
  return me->query("name")+"�Ժ���Ҫұ��ʲô�ģ������Ұɡ�";
}  