#include <command.h>
#include <ansi.h>

inherit NPC;
#include "/quest/givegift.c"
int do_copy(object me,int maxpot,int type);

string* nm1 = ({
"ÕÔ","Ç®","Ëï","Àî","ÖÜ","Îâ","Ö£","Íõ","·ë","³Â","ñÒ","ÎÀ",
"½¯","Éò","º«","Ñî","Öì","ÇØ","ÓÈ","Ðí","ºÎ","ÂÀ","Ê©","ÕÅ",
"¿×","²Ü","ÑÏ","»ª","½ð","Îº","ÌÕ","½ª","ÆÝ","Ð»","×Þ","Ó÷",
"°Ø","Ë®","ñ¼","ÕÂ","ÔÆ","ËÕ","ÅË","¸ð","ÞÉ","·¶","Åí","ÀÉ",
"Â³","Î¤","²ý","Âí","Ãç","·ï","»¨","·½","Éµ","ÈÎ","Ô¬","Áø",
"µË","±«","Ê·","ÌÆ","·Ñ","Á®","á¯","Ñ¦","À×","ºØ","Äß","ÌÀ",
"ÌÙ","Òó","ÂÞ","»ª","ºÂ","Úù","°²","³£","ÀÖ","´ô","Ê±","¸¶",
"Æ¤","±å","Æë","¿µ","Îé","Óà","Ôª","²·","¹Ë","Ó¯","Æ½","»Æ",
"ºÍ","ÄÂ","Ð¤","Òü","Ò¦","ÉÛ","Õ¿","Íô","Æî","Ã«","Óí","µÒ",
"Ã×","±´","Ã÷","²Ø","¼Æ","·ü","³É","´÷","Ì¸","ËÎ","Ã©","ÅÓ",
"ÐÜ","¼Í","Êæ","Çü","Ïî","×£","¶­","Áº","·®","ºú","Áè","»ô",
"ÓÝ","Íò","Ö§","¿Â","êÃ","¹Ü","Â¬","Ó¢","³ð","ºò","ÔÀ","Ë§",
"Ë¾Âí","ÉÏ¹Ù","Å·Ñô","ÏÄºò","Öî¸ð","ÎÅÈË","¶«·½","ºÕÁ¬","»Ê¸¦",
"Î¾³Ù","¹«Ñò","å£Ì¨","¹«ÖÎ","×ÚÕþ","å§Ñô","´¾ÓÚ","µ¥ÓÚ","Ì«Êå",
"ÉêÍÀ","¹«Ëï","ÖÙËï","Ô¯Ðù","Áîºü","ÖÓÀë","ÓîÎÄ","³¤Ëï","Ä»ÈÝ",
"Ë¾Í½","Ê¦¿Õ","ò§¿×","¶ËÄ¾","Î×Âí","¹«Î÷","Æáµñ","ÀÖÕý","ÈÀæá",
"¹«Á¼","ÍØÖº","¼Ð¹È","Ô×¸¸","¹ÈÁº","³þ½ú","ÑÖ·¨","ÈêÛ³","Í¿ÇÕ",
"¶ÎÇ§","°ÙÀï","¶«¹ù","ÄÏ¹ù","ºôÑÓ","¹éº£","ÑòÉà","Î¢Éú","ÁºÇð",
"×óÇð","¶«ÃÅ","Î÷ÃÅ","°ÛÉÍ","ÄÏ¹Ù",
"çÃ","¿º","¿ö","ºó","ÓÐ","ÇÙ","ÉÌ","Ä²","ÙÜ","¶ú","Ä«","¹þ",
"ÚÛ","Äê","°®","Ñô","Ù¡","µÚ","Îå","ÑÔ","¸£","Øá","ÖÓ","×Ú",
"ÁÖ","Ê¯",
});

string* id = ({
"zhao","qian","sun","li","zhou","wu","zhen","wang","feng","chen","zhu","wei",
"jiang","shen","han","yang","zhu","qing","you","xu","he","lu","shi","zhang",
"kong","cao","yan","hua","jin","wei","tao","jiang","qie","xie","zhou","yu",
"bo","shui","dou","zhang","yun","su","pan","ge","xi","fan","peng","lang",
"lu","wei","chang","ma","miao","feng","hua","fang","sha","ren","yuan","liu",
"deng","bao","shi","tang","fei","lian","chen","xue","lei","he","ni","tang",
"teng","yin","luo","hua","hao","wu","an","chang","le","dai","shi","fu",
"pi","bian","qi","kang","wu","yu","yuan","po","gu","ying","ping","huang",
"he","mu","xiao","yin","yao","shao","zhan","wang","qi","mao","yu","di",
"mi","bei","ming","zang","ji","fu","cheng","dai","tan","song","mao","pang",
"xiong","ji","su","qu","xiang","zhu","dong","liang","fan","hu","ling","ho",
"yu","wan","zhi","ke","jiu","guan","lu","ying","qiu","hou","yue","suai",
"sima","shangguan","ouyang","xiahou","zhuge","wenren","dongfang","helian","huangpu",
"weichi","gongyang","zhantai","gongye","zongzheng","puyang","chunyu","shanyu","taishu",
"shentu","gongshun","zhongshun","xuanyuan","linghu","zhongli","yuwen","changshun","murong",
"situ","shikong","zhuankong","duanmu","wuma","gongxi","qidiao","lezheng","xiangsi",
"gongliang","tuozhi","jiagu","zaifu","guliang","chujing","yanfa","ruye","tuqin",
"duanqian","baili","dongguo","nanguo","huyan","guihai","yangshe","weisheng","liangqiu",
"zuoqiu","dongmen","ximen","baishang","nangong",
"gou","kang","kuang","hou","you","qing","shang","mo","she","er","mo","ha",
"qiao","nian","ai","yang","dong","di","wu","yan","fu","kai","zong","zong",
"lin","shi",
});

string* nm2 = ({
"ÖÒ","Ð¢","Àñ","Òå","ÖÇ","ÓÂ","ÈÊ","¿ï","ÏÜ","Áî","¸£","Â»","´ó","Ð¡","Ïþ",
"¸ß","¿É","°¢","½ð","ÊÀ","¿Ë","Êå","Ö®","¹«","·ò","Ê±","Èô","Çì","ÎÄ","Îä",
"¶à","²Å","³¤","×Ó","ÓÀ","ÓÑ","×Ô","ÈË","Îª","Ìú","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm4 = ({      //Å®ÐÔ×¨ÓÃ
"°®","´º","µ¤","·¼","·Ò","·ï","¹Ã","ºì","ºç","½¿","¾ê",
"¾Õ","À¼","á°","Àö","Àò","Á«","Áá","ÁÕ","ÄÈ","ÇÙ","ÇÛ",
"Ù»","Æ¼","æÃ","Ï¼","Ïã","ÑÞ","Ñà","Ó¢","çø","Óñ","Õä",
"Öé",
});

void create()
{
      string weapon;
   int i = random(sizeof(nm1));
   set_name(nm1[i]+nm2[random(sizeof(nm2))]+nm4[random(sizeof(nm4))], ({id[i]}));
   set("per",35);
        set("gender", "Å®ÐÔ");
        set("age", random(20) + 15);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("combat_exp", 80000 + random(40000)); 
        set("attitude", "friendly");
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("cuff", 50);
        set_skill("blade", 50);
        set_skill("literate", 100);
        set_skill("mahayana", 150);
        set_skill("buddhism", 150);
        set_skill("jinding-zhang", 100);
        set_skill("tiangang-zhi", 100);
        set_skill("huifeng-jian", 100);
        set_skill("yanxing-dao", 100);
        set_skill("zhutian-bu", 100);
        set_skill("linji-zhuang", 100);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","yanxing-dao");
        map_skill("parry","huifeng-jian");
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 100);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: perform_action, "finger.lingkong" :),
        }) );
        set("eff_qi", 4500); 
        set("qi", 4500); 
        set("max_qi", 4500); 
        set("eff_jing", 4500); 
        set("jing", 4500); 
        set("max_jing", 4500); 
        set("eff_jingli", 4000); 
        set("neili", 5000); 
        set("max_neili", 5000);
        set("jiali", 30);
        weapon = random(2)?"/clone/weapon/gangjian":"/clone/weapon/gangjian";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int do_copy(object me,int maxpot,int type)
{
        int i,j;
        object ob;
        ob = this_object();
if (!me->query_skill("force",1))
i=10;
else        i=me->query_skill("force",1);
//        if(type==1)
//		i = i - random(20);
//		else  
//	    i = i +10+ random(10);
//        if( i < 100) i = 100;
        
        ob->set("combat_exp", (me->query("combat_exp")*3/4));
        ob->set_skill("force", i*1/2);
        ob->set_skill("sword", i*1/2);
        ob->set_skill("cuff",  i*1/2);
	ob->set_skill("blade", i*1/2);
        ob->set_skill("dodge", i*1/2);
        ob->set_skill("parry", i*1/2);
        ob->set_skill("unarmed", i*1/2);
        ob->set_skill("huifeng-jian", i*1/2);       
        ob->set_skill("zhutian-bu", i*1/2); 
        ob->set_skill("jinding-zhang", i*1/2); 
        ob->set_skill("linji-zhuang", i*1/2);         
        set_skill("linji-zhuang",i*1/2);
ob->set("jing",me->query("max_jing"));
ob->set("eff_jing",me->query("max_jing"));
ob->set("max_jing",me->query("max_jing"));
ob->set("qi",me->query("max_qi"));
ob->set("eff_qi",me->query("max_qi"));
ob->set("max_qi",me->query("max_qi"));

if (random(10)>8)
{
        ob->set_skill("force", i*3/4);
        ob->set_skill("sword", i*3/4);
        ob->set_skill("cuff",  i*3/4);
	ob->set_skill("blade", i*3/4);
        ob->set_skill("dodge", i*3/4);
        ob->set_skill("parry", i*3/4);
        ob->set_skill("unarmed", i*3/4);
        ob->set_skill("huifeng-jian", i*3/4);       
        ob->set_skill("zhutian-bu", i*3/4); 
        ob->set_skill("jinding-zhang", i*3/4); 
        ob->set_skill("linji-zhuang", i*3/4);         
        set_skill("linji-zhuang",i*3/4);
}
        ob->set("eff_jingli", me->query("eff_jingli")/2); 
        ob->set("jiali", i/6);
	ob->set("max_qi",  me->query("qi")/3); 
        ob->set("eff_jingli", me->query("eff_jingli")/2); 
        ob->set("max_neili", me->query("max_neili")/2); 
        ob->set("jiali", i/10);
        if(type==3)
		{ob->set("max_qi",     me->query("qi")/3);
		 ob->set("max_neili",  me->query("max_neili")/2); 
		}
		if(type==2)
        ob->set("max_qi",     me->query("qi")/3); 
		ob->reincarnate(); 
        ob->set("qi",ob->query("max_qi")/3);
        ob->set("neili",ob->query("max_neili")/2);
        ob->set("qi",me->query("max_qi")/3);
        ob->set("eff_qi",me->query("max_qi")/3);
        ob->set("max_qi",me->query("max_qi")/3);        
        ob->set("neili",me->query("max_neili"));
        ob->set("max_neili",me->query("max_neili"));
        ob->set("jing",me->query("max_jing")/2);
        ob->set("eff_jing",me->query("max_jing")/2);
        ob->set("max_jing",me->query("max_jing")/2);

}

void die()
{
int i,pot,exp;
	object killer;
	exp= random(10)+90;
	pot= exp*2/3;
	exp =exp/2+5;
	if(!objectp(killer = query_temp("last_damage_from")))
	return;
	if(objectp(killer = query_temp("last_damage_from"))
	&& killer->query_temp("lxhwjob")
	&& this_object()->query("usename")==killer->query("name"))

if (killer && killer->query_temp("lxhwjob")
&& this_object()->query("usename")==killer->query("name"))
{
addnl(killer,"exp",exp);
}
	destruct(this_object());

return ;
}
void init()
{
        remove_call_out("leave");
        call_out("leave",120);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "×ê½øÂ·±ßµÄÔÓ²Ý£¬²»¼ûÁË¡£\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}