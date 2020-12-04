//zhangwuji.c

#include <ansi.h>

inherit F_MASTER;
inherit F_UNIQUE;
inherit NPC;
int ask_job2();
int ask_fail2();
int ask_wldh();
#include "/quest/givegift.c"
mixed jobs = ({
        ({
"Œ“»ÒΩ∆Ï‘⁄ΩÃƒ⁄∏∫‘≤…øÛ¡∂Ã˙£¨◊ÓΩ¸…œµ»æ´Ã˙øÏ”√ÕÍ¡À£¨–Ë“™≤…ºØÃ˙øÛ",
"ƒ„¿¥µƒ’˝∫√£¨–÷µ‹√«—›¡∑’Û∑®£¨æﬁƒæ≤ªπª¡À£¨ƒ„»• ˜¡÷¿Ôø≥–© ˜∏…ø∏ªÿ¿¥",
"‘€√«∫ÒÕ¡∆Ï∏∫‘Õ⁄µÿµ¿£¨Ω´¿¥ª·”–¥Û”√≥°°£ƒ„»•∏˙µ‹–÷√«“ª∆Ω´µÿµ¿Õ⁄…Óµ„",
"Œ“∫ÈÀÆ∆Ï‘⁄ΩÃƒ⁄∏∫‘÷∆‘Ï∂æÀÆ£¨◊ÓΩ¸±˘ÀÆøÏ”√ÕÍ¡À£¨ƒ„»•±ÃÀÆ∫ÆÃ∂»°–©ÀÆ¿¥",
"–÷µ‹√«–¡–¡ø‡ø‡¡∂≥ˆ¿¥“ª–©æ´Ã˙£¨ƒ„»•”√À¸∫√∫√¥Ú‘Ïª«π",
        }),
        ({
         "–°’—","—ÓÂ–","∑∂“£","“ÛÃÏ’˝","Œ≈≤‘À…","¿‰«´","≈Ì”®”Ò","÷‹µﬂ","’≈÷–",
	"Àµ≤ªµ√","◊ØÔ£","Œ≈≤‘À…","Ã∆—Û","–¡»ª","—’‘´","“Û“∞Õı","“ÛÀÿÀÿ",
	 "¿ÓÃÏ‘´","≥Ã≥∞∑Á","∏ﬂ…ΩÕı","≥£Ω≈Ù","Ã∆—Û","∑‚π≠”∞","∫˙«‡≈£","◊ØÔ£",
	 "Œ≈≤‘À…","Ã∆—Û","–¡»ª","—’‘´","◊ØÔ£","Œ≈≤‘À…","Ã∆—Û","–¡»ª",
        }),
        });
#include "teamjob.c"
void greeting(object ob);
void create()
{
    seteuid(getuid());
    set_name("’≈Œﬁº…", ({ "zhang wuji", "zhang", "wuji" }));
    set("long", "√˜ΩÃΩÃ÷˜’≈Œﬁº…£¨Õ≥¡ÏÃÏœ¬ ÆÕÚΩÃ÷⁄£¨∫¿∆¯∏…‘∆£¨ﬂ≥ﬂÂ«ß«Ô£¨\n"
               +"°∏æ≈—Ù…Òπ¶°π°¢°∏«¨¿§¥Û≈≤“∆°π∂¿≤ΩÃÏœ¬£¨ «Ω≠∫˛÷–≤ª ¿≥ˆµƒ\n"
               +"…ŸƒÍ”¢–€°£\n");
    set("title",HIG "√˜ΩÃ"HIM"ΩÃ÷˜"NOR);
    set("gender", "ƒ––‘");
    set("age", 20);
    set("shen_type",1);
    set("attitude", "friendly");
    set("class", "fighter");

    set("per", 28);
    set("str", 86);
    set("int", 86);
    set("con", 80);
    set("dex", 80);

    set("qi", 19050);
    set("max_qi", 19050);
    set("jing", 19050);
    set("max_jing", 19050);
    set("neili", 38000);
    set("max_neili", 38000);
    set("jiali", 120);

    set("combat_exp", 9900000);
    set("score", 455000);
    
    set_skill("force", 250);
    set_skill("unarmed", 250);
    set_skill("dodge", 250);
    set_skill("parry", 250);
    set_skill("hand",250);
    set_skill("sword",250);
    set_skill("blade", 250);
    set_skill("cuff", 300);
    set_skill("strike", 300);
    set_skill("qingfu-shenfa", 380);
    set_skill("hanbing-mianzhang", 380);
    set_skill("sougu", 380);
    set_skill("jiuyang-shengong", 390);
    set_skill("qiankun-danuoyi", 380);
    set_skill("qishang-quan", 380);
    set_skill("shenghuo-shengong", 380);
    set_skill("liehuo-jian", 380);
    set_skill("lieyan-dao", 380);
    set_skill("taiji-quan",150);
    set_skill("taiji-jian",150);
    set_skill("taiji-dao",150);
    set_skill("shenghuo-ling",380);
set("jiuyangok",1);
    map_skill("force", "jiuyang-shengong");
    map_skill("dodge", "qiankun-danuoyi");
    map_skill("unarmed", "jiuyang-shengong");
    map_skill("cuff", "qishang-quan");
    map_skill("hand", "taiji-quan");
    map_skill("sword","shenghuo-ling");
    map_skill("parry","jiuyang-shengong");
    map_skill("blade","jiuyang-shengong");

    create_family("√˜ΩÃ",34, "ΩÃ÷˜");

    set("chat_chance",2);
    set("chat_msg",({
 "’≈Œﬁº…∑ﬂ»ªÀµµ¿°∞¥Û’…∑Úµ±“‘π˙Œ™º“, æË«˚…≥≥°, øπ‘™¥Û“µŒ¥≥…, Õ¨±≤»‘–Ë≈¨¡¶!°±\n",
        "’≈Œﬁº…Ãæµ¿°∞»À…˙ ß“ª÷™º∫, …˙“‡∫Œª∂, À¿“‡∫Œ”«, √Ù∂˘, ƒ„‘⁄ƒƒ¿Ô?°±\n",
        "’≈Œﬁº…µ¿°∞Œ“ΩÃ–÷µ‹Ã˝¡À: …˙”⁄¬“ ¿, µ±øÀº∫Œ™π´, ––œ¿’Ã“Â, µ¥ø‹«˝ƒß!°±\n",
//        	(: random_move :)
    }));

        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "sword.duo" :),
                (: perform_action, "sword.tougu" :),
                (: perform_action, "sword.xiyanling" :),
                (: perform_action, "sword.yinfeng" :),                
                (: perform_action, "sword.lian" :),                
                (: perform_action, "sword.can" :),                
                (: perform_action, "sword.hua" :),                                	                	
                (: perform_action, "unarmed.hun" :),                                	                	
                (: perform_action, "unarmed.jiu" :),                                	                	
                (: perform_action, "unarmed.ri" :),                                	                	
                (: perform_action, "unarmed.pi" :),                                	                	                	                	                	
                (: perform_action, "unarmed.po" :),                                	                	                	                	                	
                (: command("unwield ling") :),
                (: command("exert shield") :),
                (: command("wield ling") :),
                (: perform_action, "cuff.hunpofeiyang" :),                
                (: perform_action, "cuff.youyouhunduan" :),                
                (: perform_action, "dodge.canghaiyixiao" :),                                
        }) );
    set("inquiry",([
	  "√˜ΩÃ" :     "√˜ΩÃ’˝‘⁄±‡–¥÷Æ÷–£¨«Îæ˝…‘∫Ú°£\n",
          "Ω√´ ®Õı" : "ƒ« «Œ““Â∏∏–ª¥Ûœ¿µƒ÷∞Àæ°£\n",
          "–ª—∑" :     "À˚æÕ «Œ““Â∏∏µƒ¥Û∫≈°£\n",
          "’≈¥‰…Ω" :   "ƒ„œÎ’“Œ“∏∏«◊”– ¬˜·? \n",
          "“ÛÀÿÀÿ" :   "Œ“¬Ë «√˜◊◊˘œ¬◊œŒ¢Ã√÷˜°£\n",
          "’≈»˝∑·" :   "Œ“Ã´ ¶∏∏Ω¸¿¥ø…∫√? \n",
          "’‘√Ù" :     "»À…˙ ß“ª÷™º∫, …˙“‡∫Œª∂, À¿“‡∫Œ”«, √Ù∂˘, ƒ„‘⁄ƒƒ¿Ô?\n",
          "–°’—" :     "–°’—Œ“ø…“ª÷±ƒÓ◊≈À˝µƒ∫√¥¶°£\n",
          "÷‹‹∆»Ù" :   "’“À˝æÕ»•∂Î·“…Ω, ±¿¥∑≥Œ“°£\n",
		 "job"  : (: ask_jianxi :),
                "¡∑±¯" : (: ask_job2() :),
                "mjjob" : (: ask_job2() :),
                "≤ª¡∑±¯¡À" : (: ask_fail2() :),
                "fail" : (: ask_fail2() :),
"¡˘¥Û√≈≈…" : (: ask_wldh() :),
"Œßπ•π‚√˜∂•" : (: ask_wldh() :),
    ]));
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/damage", 660);
	set_temp("apply/armor", 660);
    setup();
    carry_object("/d/mingjiao/obj/yitianjian");
    carry_object("/clone/book/shenghuo-ling")->wield();
//    	carry_object("/d/mingjiao/obj/jiaozhumingpao")->wear();
    add_money("silver",70);
}

void init()
{
	object ob;

	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}       
	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return;
	if((int)ob->query("shen")<-50000)
	{
//      command("say
	command("wield yitian jian");
	command("hit"+(string)ob->query("id"));
        command("unwield yitian jian");
	}
	else if((int)ob->query("shen")<-5000)
	{
		command("say ƒß¥”–ƒ∆£¨”⁄Œ‰—ß≤ª¿˚£¨∆‰µ¿±ÿ÷Ô£¨»∞æ˝∑≈œ¬Õ¿µ∂£¨¡¢µÿ≥…∑.");
	}
	else if((int)ob->query("shen")<-100)
	{
		command("say ’‚Œª≈Û”—£¨»À––Ω≠∫˛£¨—‘––µ±’˝£¨«–ŒÒ◊ﬂΩ¯–∞ƒßÕ·µ¿.");
	}
	else if((int)ob->query("shen")>=0)
	{
		command("say π‚√˜’˝µ¿»Œ»À◊ﬂ£¨»∞æ˝∂‡º”±£÷ÿ.");
	}
	else if((int)ob->query("shen")>10000)
	{
		command("say ¥Ûœ¿‘⁄…œ£¨ ‹Œﬁº…“ª¿Ò£¨¥Ûœ¿À¸»’±ÿŒ™Œ‰¡÷«Ã≥˛.");
	}
	return;
}

void attempt_apprentice(object ob)
{
	if((int)ob->query("int")<20)
	{
		command("say ƒ„µƒŒÚ–‘Ã´µÕ¡À£¨≤ª  ∫œ—ßœ∞Œ“µƒπ¶∑Ú°£");
		return 0;
	}
	if((string)ob->query("gender")=="Œﬁ–‘")
	{
		command("say ƒ„—Ù∆¯≤ª◊„£¨œ∞Œ“π¶∑Úø÷Ω´◊ﬂª»Áƒß°£");
		return 0;
	}
	if((int)ob->query("shen") <= 15000)
	{
		command("say ƒ„”¶µ±∂‡◊˜–©––œ¿’Ã“Âµƒ ¬£¨“‘–ﬁ…Ì–ƒ°£");
		return 0;
	}
	command("say ∫√£¨Œ“æÕ ’œ¬ƒ„’‚Œª∫√ÕΩµ‹£°");
	command("say ƒ„µƒ÷∞ÀææÕ «±æΩÃµƒπ‚√˜ π’ﬂ°£");
	command("recruit " + ob->query("id"));
	ob->set("title", HIR"√˜ΩÃ π’ﬂ"NOR);
	return;
}

int accept_fight(object ob)
{
    if(((int)ob->query("combat_exp")<30000)&&((int)ob->query("shen")>0))
    {
        message_vision("Œ‰¡÷÷–»À◊Óº…’˘«ø∂∑∫›£¨ƒ„≤ª «Œ“µƒ∂‘ ÷£¨ªÿ»•∞…°£\n",ob);
        return 0;
    }
    message_vision("’≈Œﬁº…“ªπ∞ ÷Àµµ¿£∫’‚Œª"+RANK_D->query_respect(ob)+
	"£¨‘⁄œ¬¡ÏΩÃ¡À°£\n", ob);
    return 1;
}



void destroying(object obj, object ob, object me)
{   
   object n_money;
   int kar, exp, pot;

   return;      
}

int ask_job2()
{

        object me = this_player();
        object ob;
string skl,tar;

        skl = me->query_skills();

        if( me->query("family/family_name") != "√˜ΩÃ")
           {
                      message_vision("$N∂‘◊≈$nÀµµ¿°£’‚÷÷ ¬ø…“‘”–¿Õ±»À¥¯––£ø\n", this_object(), me);
                      return 1;
            }

        if ( !skl ) {
                tell_object(me, "ƒ„»•—ß“ª–©±æ ¬œ»∞…£°\n");
                return 1;
                }

if ((int)me->query_condition("guojob2_busy"))
           {
                      message_vision("$N∂‘◊≈$nÀµ:œ÷‘⁄√ª”–»ŒŒÒ,ƒ„µ»ª·‘Ÿ¿¥∞…!\n", this_object(), me);
                      return 1;
            }
        if ((int)me->query_condition("mj2_busy"))  
            {
                      message_vision("$N∂‘◊≈$n“°¡À“°Õ∑Àµ£∫ƒ„∏’“™π˝»ŒŒÒ,µ»ª·‘Ÿ¿¥!\n", this_object(), me);
                      return 1;
            }

        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say ƒ„µƒ«±ƒ‹Ã´…Ÿ¡À!!");
                return 1;
        }

        if (me->query_temp("mj2job")) {
                command("kick " + me->query("id"));
                command("say Œ“≤ª «∏¯¡Àƒ„»ŒŒÒ¡À¬£ø");
                return 1;
                }
        else {

tar = jobs[1][random(sizeof(jobs[1]))];
skl = jobs[0][random(sizeof(jobs[0]))];        
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "  Œ“ΩÃƒøµƒ‘⁄”Î∑¥øπ‘™±¯£¨œ÷‘⁄’˝‘⁄¡∑±¯  £");
                command("say " + me->query("id") + " °∫" + skl  + "°ª£°" NOR);
                command("say " + me->query("id") + "  Œ“ΩÃ°∫" + tar  + "°ª’˝‘⁄◊ˆ’‚º˛ ¬£¨ƒ„»•–≠÷˙(xiezhu)À˚∞…£°" NOR);
        me->delete_temp("mjjob2");
                me->set_temp("mj2job", tar);
                ob = new(__DIR__"ling");
                ob->set("usename",me->query("name"));
                ob->move(me);
                command("say " + me->query("id") + "  ’‚∏ˆŒÂ––∆Ï£¨ƒ„ƒ√∫√£¨∆æ’‚∏ˆ»•◊ˆ∞…£°" NOR);
                return 1;
               }                              
}

int ask_fail2()
{
        object me = this_player();
        
        if (me->query_temp("mj2job")) {
                command("sigh");
                command("say ’‚√¥µ„ ¬£¨ƒ„∂º◊ˆ≤ª∫√£¨“≤∞’£¨ƒ„»•∞….");
                me->apply_condition("mj2_busy", 5 +
                        (int)me->query_condition("mj2_busy"));

me->delete_temp("mj2job");
me->delete_temp("mj2skl");
me->delete_temp("mj2jobs");
                return 1;
                }
}


int ask_wldh()
{

        object me = this_player();
        object ob,where,who,fang;
        mapping quest;
        mapping skl; 
        string *sname, place;        
	
        int i, skill = 0;
	
        ob=this_object();
        who=me;
        where = environment(who);
        if(((int)me->query("jinyong/book12")!=3))
           {
                      message_vision("$N∂‘◊≈$nÀµµ¿°£‘› ±√ª”–¡˘¥Û≈…œ˚œ¢°£\n", this_object(), me);
	                      return 1;
            }

        if(!me->query_temp("book1242"))
           {
                      message_vision("$N∂‘◊≈$nÀµµ¿°£‘› ±√ª”–¡˘¥Û≈…œ˚œ¢°£\n", this_object(), me);
	                      return 1;
            }


                command("bow " + me->query("id"));
                message_vision("$N∂‘◊≈$nÀµµ¿°£¡˘¥Û≈…“—æ≠…±…œ¿¥¡À£°\n", this_object(), me);
                //command("say " + me->query("id") + "Œ“ŒÂµ‹“—æ≠ªÿ¿¥¡À£¨µ´ŒÂ¥Û≈……œ√≈¿¥Ã÷“™–ª—∑µƒœ¬¬‰£°" NOR);
                //command("say " + me->query("id") + "Œ“√«∫œ¡¶¥Ú∞‹À˚√«∞…£°" NOR);
                call_out("leavet",1);

                return 1;
                             
}
void leavet()
{
        object ob = this_player();
 ob->move("/d/mingjiao/yttl");
 //message_vision("$N∑……ÌœÚÕ‚Ã”»•£°\n" NOR,this_object());
 //       destruct(this_object());
}  