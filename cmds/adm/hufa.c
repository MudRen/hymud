
int main(object me, string arg)
{
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
//----���»�ӭ��ӣ�nm2��Ҫһ���Ŀ��֣��Ա����������--------------
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

mixed npcs = ({
        ({
        "/kungfu/class/wudang/zhang",
        "/kungfu/class/shaolin/da-mo",
"/quest/menpaijob/emei/miejue",
"/kungfu/class/huashan/feng",
"/kungfu/class/lingjiu/tonglao",
"/kungfu/class/lingjiu/li",
"/kungfu/class/taohua/huang",
"/quest/menpaijob/xingxiu/ding",
"/kungfu/class/btshan/ouyangfeng",
"/quest/menpaijob/shenlong/hong",
"/kungfu/class/xueshan/fawang",
"/kungfu/class/xueshan/jiumozhi",
"/kungfu/class/xueshan/xuedao",
"/quest/menpaijob/yunlong/chen",
"/quest/menpaijob/mingjiao/zhangwuji",
"/quest/menpaijob/gumu/zf/longnv",
"/quest/menpaijob/gumu/yangguo",
"/kungfu/class/gaibang/hong",
"/d/quanzhen/npc/wang",
"/kungfu/class/dali/duanzc",
"/d/yinju/npc/yideng",
"/d/tianlongsi/npc/kurong",
"/d/xiaoyao/npc/xiaoyaozi",
"/d/nanshaolin/nanshaolin/tianhong",
"/d/nanshaolin/nanshaolin/tianjing",
"/d/tiezhang/npc/qqren",
"/d/tiezhang/npc/sgjn",
"/d/mr/npc/murong-bo",
"/d/mr/npc/murong-fu",
"/kungfu/class/kunlun/hezudao",
"/d/heimuya/npc/dongfang",
"/d/heimuya/npc/renwoxing",
"/d/lingxiao/npc/bai-wanjian",
"/d/lingxiao/npc/bai",
"/d/wudujiao/npc/hetieshou",
"/d/wudujiao/npc/hehongyao",
"/d/tangmen/npc/tang",
"/d/feitian/npc/biguqing",
"/d/feitian/npc/tianfeng",
"/kungfu/class/honghua/chen-jialuo",
"/kungfu/class/qingcheng/yu",
"/kungfu/class/taishan/tianmen",
"/kungfu/class/songshan/zuo",
"/kungfu/class/henshan/moda",
"/kungfu/class/hengshan/xian",
"/kungfu/class/hu/hufei",
"/kungfu/class/miao/miao",
"/d/meizhuang/npc/huangzhong-gong",
"/d/meizhuang/npc/danqing-sheng",
"/d/meizhuang/npc/tubi-weng",
"/d/jinghai/npc/master1",
"/d/jinghai/npc/master2",
"/d/hainan/npc/master",
"/d/xiakedao/npc/mu",
"/d/xiakedao/npc/long",
"/d/xibei/kongdong/npc/mu",
        }),
        });

   string HUFA_FILE = npcs[0][random(sizeof(npcs[0]))];
   object hufa;
   int i;

object *enemy;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
int k,a,b,c,d,e,f,temp;
   seteuid(getuid());
        

		if( environment(me)->query("no_fight") )
		return notify_fail("����û���˴򶷣�\n");
   //last 0 means do not show position.

   if (me->query("jing")<100) 
	return notify_fail("�㾫����!!\n");


//   me->save();


   message_vision("ֻ��$N���һ�����������ڣ�������\n", me);
   hufa = new(HUFA_FILE);
   hufa->move(environment(me));
   	 //hufa->set_name(me->query("name")+"�Ļ���",({"dizi"}));
   
    i = random(sizeof(names));
  hufa->set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], ({ids[i]}));
   hufa->set("combat_exp",me->query("combat_exp")/2);
   hufa->set("possessed", me);
     hufa->set("combat_exp", (me->query("combat_exp")));
	hufa->set("max_qi",  me->query("max_qi")); 
	hufa->set("max_jing",  me->query("max_jing")); 
        hufa->set("eff_jingli", me->query("eff_jingli")); 
        hufa->set("max_neili",  me->query("max_neili")); 
hufa->set("str",  me->query("str")); 
hufa->set("dex",  me->query("dex")); 
hufa->set("con",  me->query("con")); 
hufa->set("int",  me->query("int")); 
 hufa->set("jiali", random(300)+1);     
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
if (!me->query_skill("force")) e=320;
if (e<= 300) e=320;
if (mapp(skill_status = hufa->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
{
skill_status = hufa->query_skills();
sname = keys(skill_status);//���������Լ��Ĺ�������
temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
hufa->set_skill(sname[i],e);//ɾ���Լ����й���
}

   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       hufa->set_temp("apply/defense", 200);
        hufa->set_temp("apply/armor", 500);
        hufa->set_temp("apply/damage", 200);
        hufa->set_temp("apply/attack", 200);		
	}	



      hufa->set("owner_id", (string)me->query("id")); 
   hufa->set_leader(me);



   hufa->show(me);
    me->add("jing",-100); 
	   	if(me->is_fighting()) {
  enemy = me->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			hufa->kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(hufa);
			else enemy[i]->kill_ob(hufa);
		}
	}
//me->remove_all_killer();
	}
      return 1;
}
 


int help(object me)
{
    write(@HELP
ָ���ʽ: alert 
 
��Ϊ������а���ɵ��������������ٻ����������������Լ���
����whisper���Լ��Ļ�����������磬�����Ļ�����aaa-zuo����
whisper aaa-zuo kill xiao er����������ɱ��С����

HELP
    );
   return 1;
}
 
