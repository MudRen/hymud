// xiaofeng.c 萧峰(乔峰)

#include <ansi.h>

inherit NPC;
int ask_me();
void check_skills(object ob);
int waiting(object me, object dest);
int checking(object me, object dest);
int do_back(object me);
int do_kill(object me, object dest);

void create()
{
	set_name("萧峰", ({"xiao feng", "xiao", "feng"}));
	set("gender", "男性");
	set("nickname",HIB"铁掌降龙"NOR);
	set("age", 28);
	set("long", 
		"他就是丐帮前任帮主，因被发现是契丹人而众叛亲离。\n"
		"在江湖上与燕子坞的慕荣复并称为「北乔峰，南慕荣」。\n"
		"他身穿一件普通的粗布褂子，腰间用一条麻绳随便一系。\n"
		"他身高六尺有余，体格十分魁梧，长有一张线条粗旷、十\n"
		"分男性化的脸庞，双目如电，炯炯有神。\n");
	set("attitude", "peaceful");
	
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("chat_chance", 1);
	set("chat_msg", ({
		"萧峰叹了口气道：“唉……想不到我萧峰大好男儿，居然被马夫人这样一个女子所骗！\n",
		"萧峰喃喃道：“我们丐帮的「降龙十八掌」是天下最霸道的掌法。”\n",

	}));

	        set("inquiry", ([
                "营救" : (: ask_me :),
        ]) );
	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	
	set("combat_exp", 180000);
	set("score", 20000);
	 
	set_skill("force", 120);             // 基本内功
	set_skill("huntian-qigong", 120);    // 混天气功
	set_skill("unarmed", 120);           // 基本拳脚
	set_skill("xianglong-zhang", 120);   // 降龙十八掌
	set_skill("dodge", 120);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 120);        // 逍遥游
	set_skill("parry", 120);             // 基本招架
	set_skill("begging", 50);            // 叫化绝活
	set_skill("checking", 50);           // 道听途说
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}



int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);


	  	if(!who->query_temp("killtlbb10"))
	{
		message_vision("$N对$n说道： 阿紫现在怎么样了？ 我对不起她姐姐，不能再对不起她了。\n",this_object(),who);
		 
		return 1;	
	}


	  	if(((int)who->query("jinyong/book4")!=9))
	{
		message_vision("$N对$n说道： 我听不懂,你在说什么啊！\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}	

	  	if(((int)who->query("jinyong/book4")>=10))
	{
		message_vision("$N对$n说道： 我听不懂,你在说什么啊！\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}
	

	
	command("bow " + who->query("id"));
	message_vision("$N对$n说道： 谢谢这位兄弟的教命之恩。\n",this_object(),who);


	
	i = 1000+random(3800);
	who->set("jinyong/book4",10);
	who->add("combat_exp",i+26880);
	who->add("potential",i*28);
	who->add("mpgx",20);
	who->add("expmax",2);

	tell_object (who,"你赢得了"+chinese_number(i+26880)+"点经验"+
	           chinese_number(i*28)+"点潜能"+"二十点门派贡献 二点成长上限！！\n");
message("channel:chat", HIB"【海洋III】听说"+who->name() + "完成了天龙八部的所有任务!"NOR"\n", users());
	who->save();
	call_out("destroying", 0);                       
	return 1;
}
void destroying()
{   
object ob=this_object();
   message_vision(HIM"$N说完闪了闪身就消失在门外......\n"NOR,ob);
destruct(this_object());
   return;      
}