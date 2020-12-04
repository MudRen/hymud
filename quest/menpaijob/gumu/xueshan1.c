// /kungfu/class/xueshan/fawang.c  ���ַ���
// by secret

#include <ansi.h>
inherit NPC;
#include "/quest/givegift.c"
int do_copy(object me);
int do_back(object me);
string* names = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��",
"��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��",
"��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��",
"Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��",
"��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��",
"��","��","֧","��","��","��","¬","Ӣ","��","��","��","˧",
"˾��","�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�",
"ξ��","����","�̨","����","����","���","����","����","̫��",
"����","����","����","ԯ��","���","����","����","����","Ļ��",
"˾ͽ","ʦ��","��","��ľ","����","����","���","����","����",
"����","��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��",
"��ǧ","����","����","�Ϲ�","����","�麣","����","΢��","����",
"����","����","����","����","�Ϲ�",
"��","��","��","��","��","��","��","Ĳ","��","��","ī","��",
"��","��","��","��","١","��","��","��","��","��","��","��",
"��","ʯ",
});

string* ids = ({
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
//----���»�ӭ���ӣ�nm2��Ҫһ���Ŀ��֣��Ա����������--------------
string* nm2 = ({
"��","Т","��","��","��","��","��","��","��","��","��","»","��","С","��",
"��","��","��","��","��","��","��","֮","��","��","ʱ","��","��","��","��",
"��","��","��","��","��","��","��","��","Ϊ","��","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"��","��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","�","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","��","��","��","ǿ","��","ɽ",
"̩","��","ͦ","ΰ","��","��","��","��",
"��","�","��","��","��","��",
});

void create()
{
   int i = random(sizeof(names));
  set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], ({"fawang"}));
	set("per", 35);
        set("long",@LONG
����ѩɽ�µĻ��̵���,����һ���Ϻ����ģ�ͷ��ɮñ��
LONG
        );
        set("gender", "����");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 5000);
        set("max_jing", 5000);
        set("neili", 14500);
        set("max_neili", 14500);
        set("jiali", 100);
        set("combat_exp", 2500000);
        set("score", 200000);

        set_skill("necromancy", 100);
        set_skill("force", 200);
        set_skill("longxiang", 300);
        set_skill("dodge", 200);
        set_skill("shenkong-xing", 300);
        set_skill("unarmed", 200);
        set_skill("yujiamu-quan", 300);
        set_skill("parry", 220);
        set_skill("cuff", 200);
        set_skill("sword", 100);
        set_skill("mingwang-jian", 250);
        set_skill("lamaism", 250);
        set_skill("literate", 200);
        set_skill("hammer", 200);
        set_skill("riyue-lun", 300);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "riyue-lun");
        map_skill("sword", "mingwang-jian");
        map_skill("hammer", "riyue-lun");
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 350);
        set_temp("apply/damage", 350);
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
(: perform_action, "hammer.wushuai" :),
                (: perform_action, "hammer.wulundafa" :),
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );

        create_family("ѩɽ��", 3, "���̵���");
        set("class", "bonze");

        setup();
        carry_object("/d/xueshan/obj/jinlun")->wield();
        carry_object("/d/xueshan/obj/p-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
}

int checking(object ob, object me)
{
	if(!me || !present(me, environment())) do_back(ob);
	else call_out("checking", 2, ob, me);
        return 1;
}
int do_back(object ob)
{
        ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "���·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}

int do_copy(object me)
{
        int i;
        object ob;
        me = this_player();
        ob = this_object();

      if(!me->query_temp("xx_rob")){
      	   do_back(me);
      	   return 0;
      	   }
        message_vision(HIR"ͻȻ�Ӹ����ܳ�һ��$N��������˵��������$n��\n"NOR, ob, me);
        me->add_temp("biaoshi", 1);
        
        ob->set("combat_exp",me->query("combat_exp") );
        ob->set("max_qi",me->query("max_qi")/2);
        ob->set("eff_qi",me->query("max_qi")/2);
        ob->set("qi",me->query("max_qi")/2);
        ob->set("max_jing",me->query("max_jing")/2);
        ob->set("eff_jing",me->query("max_jing")/2);
        ob->set("jing",me->query("max_jing")/2);

        ob->set("max_jingli",me->query("max_jingli")* 3 / 4);
        ob->set("eff_jingli",me->query("max_jingli")* 3 / 4);
        ob->set("jingli",me->query("max_jingli")* 3 / 4);
        ob->set("max_neili",me->query("max_neili")* 3 / 4);
        ob->set("neili",me->query("max_neili")* 3 / 4);

        ob->set("max_neili",me->query("max_neili"));
        ob->set("neili",me->query("max_neili"));

        ob->set_skill("force", me->query_skill("force",1));
        ob->set_skill("longxiang", me->query_skill("force",1)* 3 / 4);
        ob->set_skill("shenkong-xing", me->query_skill("force",1)* 3 / 4);
        ob->set_skill("yujiamu-quan", me->query_skill("force",1)* 3 / 4);
        ob->set_skill("riyue-lun",me->query_skill("force",1)* 3 / 4);
        ob->set_skill("dodge", me->query_skill("force",1)* 3 / 4); 
        ob->set_skill("sword", me->query_skill("force",1)* 3 / 4); 
        ob->set_skill("mingwang-jian", me->query_skill("force",1)* 3 / 4); 
        ob->set_skill("parry",me->query_skill("force",1)* 3 / 4); 
        ob->set_skill("hammer", me->query_skill("force",1)* 3 / 4);
        ob->set_skill("unarmed", me->query_skill("force",1)* 3 / 4); 

        ob->kill_ob(me);
	 me->kill_ob(ob);
        checking(ob, me);    
        call_out("do_back", 350,  ob);  
        return 1;
}

void die()
{
int i,pot,exp;
	object killer;
	exp= random(50)+50;
	pot= exp*2/3;
	exp=exp/2+1;
	if(objectp(killer = query_temp("last_damage_from")))
{

addnl(killer,"exp",exp);;
}
	destruct(this_object());

return ;
}

void init()
{
        remove_call_out("leave");
        call_out("leave",350);
}


void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "���·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}