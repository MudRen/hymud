// Last Modified by Winder on May. 15 2001
// /clone/misc/dache.c
// sign/value���������ٵ���

inherit ITEM;
#include <ansi.h>
int do_go(string);
int look_sign();
mapping *sign=({
	([	"name"   : "�������",
		"target" : "���������ʯ��",
		"id"     : "heimuya",
		"out"    : "heimuya",
		"file"   : "/d/heimuya/road1",
		"value"  : 200,
		"time"   : 10
	]),
	([	"name"   : "����ɽ",
		"target" : "����ɽׯ",
		"id"     : "luoyan",
		"out"    : "luoyan",
		"file"   : "/d/yandang/luoyan2",
		"value"  : 200,
		"time"   : 10
	]),
	([	"name"   : "���Ʒ�",
		"target" : "���Ʒ�ɽ����",
		"id"     : "tiezhang",
		"out"    : "tiezhang",
		"file"   : "/d/tiezhang/shanjiao",
		"value"  : 200,
		"time"   : 10
	]),
	([	"name"   : "÷ׯ",
		"target" : "÷ׯ����",
		"id"     : "meizhuang",
		"out"    : "meizhuang",
		"file"   : "/d/meizhuang/gate",
		"value"  : 200,
		"time"   : 10
	]),
	([	"name"   : "Ľ������",
		"target" : "Ľ������",
		"id"     : "taihu",
		"out"    : "yanziwu",
		"file"   : "/d/mr/matou",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "����ɽ",
		"target" : "����ɽ��",
		"id"     : "wuliang",
		"out"    : "wuliang",
		"file"   : "/d/dali/wuliang/xiaolu1",
		"value"  : 300,
		"time"   : 10
	]),
	([	"name"   : "������",
		"target" : "��������ɽ",
		"id"     : "tianshan",
		"out"    : "xiyu",
		"file"   : "/d/xingxiu/tianroad2",
		"value"  : 300,
		"time"   : 10
	]),
	([	"name"   : "������",
		"target" : "������ʯ��",
		"id"     : "lingxiao",
		"out"    : "lingxiao",
		"file"   : "/d/lingxiao/shiya",
		"value"  : 200,
		"time"   : 10
	]),
	([	"name"   : "ѩɽ��",
		"target" : "ѩɽ��ɽ��",
		"id"     : "xueshan",
		"out"     : "xueshansi",
		"file"   : "/d/xueshan/shanmen",
		"value"  : 300,
		"time"   : 10
	]),
	([	"name"   : "������",
		"target" : "������ɽ��",
		"id"     : "mingjiao",
		"out"    : "mingjiao",
		"file"   : "/d/mingjiao/shanmen",
		"value"  : 300,
		"time"   : 10
	]),
	([	"name"   : "����ɽ",
		"target" : "����ɽ����",
		"id"     : "zhongtiao",
		"out"    : "zhongtiao",
		"file"   : "/d/huashan/jzroad3",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "����ɽ",
		"target" : "����ɽ�׺�",
		"id"     : "changbai",
		"out"    : "changbai",
		"file"   : "/d/guanwai/baihe",
		"value"  : 300,
		"time"   : 10
	]),
	([	"name"   : "ȫ����",
		"target" : "ȫ����ɽ��",
		"id"     : "zhongnan",
		"out"    : "zhongnan",
		"file"   : "/d/quanzhen/shanjiao",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "��ɽ",
		"target" : "��ɽ����Ͽ",
		"id"     : "hengshan",
		"out"    : "hengshan",
		"file"   : "/d/hengshan/jinlongxia",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "��ɽ",
		"target" : "��ɽ������",
		"id"     : "henshan",
		"out"    : "henshan",
		"file"   : "/d/henshan/lingxingmen",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "��ɽ",
		"target" : "��ɽɯ��ƺ",
		"id"     : "huashan",
		"out"    : "huashan",
		"file"   : "/d/huashan/shaluo",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "̩ɽ",
		"target" : "̩ɽ��ڷ�",
		"id"     : "taishan",
		"out"    : "taishan",
		"file"   : "/d/taishan/daizong",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "��ɽ",
		"target" : "��ɽ̫����",
		"id"     : "songshan",
		"out"    : "songshan",
		"file"   : "/d/songshan/taishique",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "���ɽ",
		"target" : "��ǽ�����",
		"id"     : "qingcheng",
		"out"    : "qingcheng",
		"file"   : "/d/qingcheng/jianfugong",
		"value"  : 200,
		"time"   : 10
	]),
	([	"name"   : "����ɽ",
		"target" : "������ɽ��",
		"id"     : "kunlun",
		"out"    : "kunlun",
		"file"   : "/d/kunlun/shanmen",
		"value"  : 300,
		"time"   : 10
	]),
	([	"name"   : "��üɽ",
		"target" : "��ü������",
		"id"     : "emei",
		"out"    : "emei",
		"file"   : "/d/emei/bgs",
		"value"  : 200,
		"time"   : 10
	]),
	([	"name"   : "�䵱ɽ",
		"target" : "�䵱�⽣��",
		"id"     : "wudang",
		"out"    : "wudang",
		"file"   : "/d/wudang/jiejianyan",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "��������",
		"target" : "������ӭ��ͤ",
		"id"     : "nanshaolin",
		"out"    : "nanshaolin",
		"file"   : "/d/nanshaolin/ting",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "������",
		"target" : "������ɽ��",
		"id"     : "shaolin",
		"out"    : "shaolin",
		"file"   : "/d/shaolin/shanmen",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "����",
		"target" : "��������㳡",
		"id"     : "yangzhou",
		"out"    : "city",
		"file"   : "/d/city/guangchang",
		"value"  : 100,
		"time"   : 10
	]),

	([	"name"   : "�嶾��",
		"target" : "�嶾���һ���",
		"id"     : "wudujiao",
		"out"    : "wudujiao",
		"file"   : "/d/wudujiao/xiao3",
		"value"  : 100,
		"time"   : 10
	]),	
	([	"name"   : "�����ԯ��",
		"target" : "�����ԯ��",
		"id"     : "kongdong",
		"out"    : "kongdong",
		"file"   : "/d/xibei/kongdong/xuanyuan_gong",
		"value"  : 400,
		"time"   : 20
	]),
	([	"name"   : "����������",
		"target" : "����������",
		"id"     : "tianlongsi",
		"out"    : "tianlongsi",
		"file"   : "/d/tianlongsi/damen",
		"value"  : 500,
		"time"   : 20
	]),	
	([	"name"   : "��������",
		"target" : "��������",
		"id"     : "tangmen",
		"out"    : "tangmen",
		"file"   : "/d/tangmen/zhulin",
		"value"  : 500,
		"time"   : 20
	]),	

	([	"name"   : "̫ԭ��",
		"target" : "̫ԭ��",
		"id"     : "taiyuan",
		"out"    : "taiyuan",
		"file"   : "/d/taiyuan/xidajie1",
		"value"  : 100,
		"time"   : 10
	]),	

	([	"name"   : "�Ϸʳ�",
		"target" : "�Ϸʳ�",
		"id"     : "hefei",
		"out"    : "hefei",
		"file"   : "/d/hefei/xidajie3",
		"value"  : 100,
		"time"   : 10
	]),	
	([	"name"   : "�Ž���",
		"target" : "�Ž���",
		"id"     : "jiujiang",
		"out"    : "jiujiang",
		"file"   : "/d/jiujiang/dongdajie2",
		"value"  : 100,
		"time"   : 10
	]),	
	([	"name"   : "�����",
		"target" : "�����",
		"id"     : "baling",
		"out"    : "baling",
		"file"   : "/d/baling/dongdajie1",
		"value"  : 500,
		"time"   : 30
	]),	

	([	"name"   : "��Ҷ��",
		"target" : "��Ҷ��",
		"id"     : "suiye",
		"out"    : "suiye",
		"file"   : "/d/suiye/beidajie1",
		"value"  : 300,
		"time"   : 30
	]),	
	
	([	"name"   : "�����",
		"target" : "�����",
		"id"     : "dingxiang",
		"out"    : "dingxiang",
		"file"   : "/d/dingxiang/beidajie1",
		"value"  : 300,
		"time"   : 30
	]),	
	
	([	"name"   : "�½�������",
		"target" : "�½�������",
		"id"     : "xinjiang",
		"out"    : "xinjiang",
		"file"   : "/d/xinjiang/nanmen",
		"value"  : 600,
		"time"   : 30
	]),			

	([	"name"   : "���ݳ�",
		"target" : "���ݳ�",
		"id"     : "xuzhou",
		"out"    : "xuzhou",
		"file"   : "/d/xuzhou/xidajie",
		"value"  : 300,
		"time"   : 20
	]),	

	([	"name"   : "������",
		"target" : "������",
		"id"     : "guizhou",
		"out"    : "guizhou",
		"file"   : "/d/guizhou/center",
		"value"  : 300,
		"time"   : 20
	]),	

	([	"name"   : "�ϲ���",
		"target" : "�ϲ���",
		"id"     : "nanchang",
		"out"    : "nanchang",
		"file"   : "/d/nanchang/center",
		"value"  : 300,
		"time"   : 20
	]),	

	([	"name"   : "��ɳ��",
		"target" : "��ɳ��",
		"id"     : "changsha",
		"out"    : "changsha",
		"file"   : "/d/changsha/guangchang",
		"value"  : 300,
		"time"   : 20
	]),	
	
		([	"name"   : "��Զ��",
		"target" : "��Զ��",
		"id"     : "ny",
		"out"    : "ny",
		"file"   : "/d/ny/postoffice",
		"value"  : 300,
		"time"   : 20
	]),

		([	"name"   : "����ʢ��",
		"target" : "����ʢ��",
		"id"     : "shengjing",
		"out"    : "fengtian",
		"file"   : "/d/fengtian/cross",
		"value"  : 300,
		"time"   : 20
	]),

	([	"name"   : "���չ�",
		"target" : "���չ�����",
		"id"     : "lingjiu",
		"out"    : "lingjiu",
		"file"   : "/d/lingjiu/dating",
		"value"  : 300,
		"time"   : 30
	]),

	([	"name"   : "����ɽׯ",
		"target" : "����ɽׯ����",
		"id"     : "baituo",
		"out"    : "baituo",
		"file"   : "/d/baituo/dating",
		"value"  : 300,
		"time"   : 30
	]),	
	([	"name"   : "�һ���",
		"target" : "�һ�������",
		"id"    : "taohua",
		"out"    : "taohua",
		"file"   : "/d/taohua/dating",
		"value"  : 300,
		"time"   : 30
	]),	
	([	"name"   : "������",
		"target" : "�����̴���",
		"id"    : "shenlong",
		"out"    : "shenlong",
		"file"   : "/d/shenlong/dating",
		"value"  : 300,
		"time"   : 30
	]),

	([	"name"   : "��Ż�����",
		"target" : "��Ż���������",
		"id"    : "feitian",
		"out"    : "feitian",
		"file"   : "/d/feitian/damen",
		"value"  : 300,
		"time"   : 30
	]),
	([	"name"   : "�컨��",
		"target" : "�컨�����",
		"id"    : "honghua",
		"out"    : "honghua",
		"file"   : "/d/huizhu/damen",
		"value"  : 300,
		"time"   : 30
	]),

	([	"name"   : "��ػ�",
		"target" : "��ػ����",
		"id"    : "tiandihui",
		"out"    : "tiandihui",
		"file"   : "/d/beijing/dating",
		"value"  : 300,
		"time"   : 30
	]),
	([	"name"   : "��Ĺ��",
		"target" : "��Ĺ�ɴ���",
		"id"    : "gumu",
		"out"    : "gumu",
		"file"   : "/d/gumu/zhengting",
		"value"  : 300,
		"time"   : 30
	]),
	([	"name"   : "����",
		"target" : "��������",
		"id"    : "dali",
		"out"    : "dali",
		"file"   : "/d/dali/wangfugate",
		"value"  : 300,
		"time"   : 30
	]),
	([	"name"   : "ؤ��",
		"target" : "ؤ������",
		"id"    : "gaibang",
		"out"    : "gaibang",
		"file"   : "/d/city/pomiao",
		"value"  : 300,
		"time"   : 30
	]),	
	([	"name"   : "���͵�",
		"target" : "���͵�����",
		"id"    : "xiakedao",
		"out"    : "xiakedao",
		"file"   : "/d/xiakedao/shiroom24",
		"value"  : 300,
		"time"   : 30
	]),
	([	"name"   : "������",
		"target" : "�����ִ���",
		"id"    : "baiyun",
		"out"    : "baiyun",
		"file"   : "/d/hainan/jingtang",
		"value"  : 300,
		"time"   : 30
	]),
	([	"name"   : "������",
		"target" : "�����ɴ���",
		"id"    : "jinghai",
		"out"    : "jinghai",
		"file"   : "/d/jinghai/jhd20",
		"value"  : 300,
		"time"   : 30
	]),
	([	"name"   : "���",
		"target" : "��Ҵ���",
		"id"    : "miaojia",
		"out"    : "miaojia",
		"file"   : "/d/zhongzhou/miaojia_men",
		"value"  : 300,
		"time"   : 30
	]),	
	([	"name"   : "��ң��",
		"target" : "��ң�ɲ�ƺ",
		"id"    : "xiaoyao",
		"out"    : "xiaoyao",
		"file"   : "/d/xiaoyao/qingcaop",
		"value"  : 300,
		"time"   : 30
	]),		
	([	"name"   : "����������",
		"target" : "������",
		"id"    : "dazao",
		"out"    : "dazao",
		"file"   : "/p/newweapon/xiaowu",
		"value"  : 100,
		"time"   : 20
	]),		
 


});
void setup()
{}
void init()
{
	add_action("do_go", "qu");
	add_action("look_sign", "kan");
}
void create()
{
	set_name("��", ({"da che", "che", "dache"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","����һ�����²��ɵĴ󳵣���������һ�����ϲ��ϵĳ���
�������ϸ����(kan)���Ϲ��ŵ����ӣ��Ǿ�������ϴ󳵣�\n����ȥ(qu)�ĵط���\n");
		set("unit", "��");
		set("no_fight",1);
		set("no_get", 1);
		set("no_steal", 1);
		set("no_beg", 1);
		set("no_drop", 1);
		set("no_put", 1);
	}
	setup();
}
int look_sign()
{
	string adjstr1, adjstr2, str="�ɴ�ȥ(qu)�����еط���\n  Ŀ�ĵ�        ����          ����\n================================================\n";
	int adj1, adj2, i=sizeof(sign);
	while (i--)
	{
		if(environment(this_player())->query("outdoors")!=sign[i]["out"])
		{
			str += " "+sign[i]["target"];
			adjstr1 = sign[i]["target"];
			adj1 = 18-strlen(adjstr1);
			while (adj1--) str += " ";
			str += "("HIY + sign[i]["id"] + NOR") ";
			adjstr2 = "(" + sign[i]["id"] + ") ";
			adj2 = 18-strlen(adjstr2);
			while (adj2--) str += " ";
			str += "��"CYN+MONEY_D->price_str(sign[i]["value"]) + NOR"\n";
		}
	}
	write(str+"------------------------------------------------\n");
	return 1;
}

void do_move(object ob, int i)
{
	ob->delete_temp("block_msg/all");
	ob->delete_temp("noliving");
	write("���ڵ�"+sign[i]["name"]+"�ˡ�\n\n");
	ob->move(sign[i]["file"]);
	tell_room(environment(ob), "\n��ȻԶ����һ���󳵷ɳ۶������쵽�����ʱ������ͣ��������\n" + ob->name() + "�Ӵ�������������\n", ({ob}));
}

int do_go(string arg)
{
	object *inv, ob=this_player();
	int j, i=sizeof(sign);

	if (!arg) return notify_fail("��Ҫȥ����ȿ���(kan)���߰ɣ�\n");
	if (ob->is_busy() || ob->is_fighting())
		return notify_fail("����æ���أ�\n");

	inv = all_inventory(ob);
	for (j = 0; j < sizeof(inv); j++)
	{
		if (inv[j]->is_character())
		{
			write("������λ�����ޣ���������ô���ˡ�\n");
			return 1;
		}
	}
	 if (  ob->query_temp("LAST_PKER_TIME") && 
             time() - ob->query_temp("LAST_PKER_TIME")<7200 && !wizardp(ob))
             return notify_fail("ɱ���ˣ��ɲ�������ͷ�ڹ꣡\n");

	while(i--)
	{
		if (arg == sign[i]["id"])
		{
			if(environment(ob)->query("outdoors") == sign[i]["out"])
				return notify_fail("����Ц����������Ϳ����ȥʲôȥ���㲻���Ѿ���"HIR+ sign[i]["name"] +NOR"���𣿣���\n");
			switch (MONEY_D->player_pay(ob, sign[i]["value"]))
			{
				case 0:
					return notify_fail("��⵰��һ�ߴ���ȥ��\n");
				case 2:
					return notify_fail("����Ǯ��\n");
			}
			message_vision("\n$N�����˴󳵣�һ���ֶ���" + chinese_number(sign[i]["value"]/100) + "�����Ӹ�����˵��������ȥ" +sign[i]["name"]+ "����\n$N˵���ƿ����ӣ�һ���������ȥ��\n\n", ob);
			write(HIC"����"NOR" -
    ����ɸɾ�����������������Ĵ����ӡ����������������������
��϶��͸���������⿴�����ľ��£��е�׳�ۣ��е�Ҳ��Ȥ�����ǻ��
������˯ȥ��Ҳ����·�����˶�á��������һ�����壬���������š�
��������ǰ�棬һ·������һ·����غ���ʲôС����\n");
			ob->set_temp("nbjob23",1);
			ob->set_temp("noliving/journey", 1);
			ob->set_temp("block_msg/all", 1);
			ob->move("/clone/misc/dachenei");
			call_out("do_move", sign[i]["time"]+random(10), ob, i);
			return 1;
		}
	}
	return notify_fail("��Ҫȥ���\n");
}
/*
������ɽ��   (shaolin)    /d/shaolin/shanmen
�䵱�⽣��   (wudang)     /d/wudang/jiejianyan
��ü������   (emei)       /d/emei/bgs
������ɽ��   (kunlun)     /d/kunlun/shanmen
��ǽ�����   (qingcheng)  /d/qingcheng/jianfugong
��ɽ̫����   (songshan)   /d/songshan/taishique
̩ɽ��ڷ�   (taishan)    /d/taishan/daizong
��ɽɯ��ƺ   (huashan)    /d/huashan/shaluo
��ɽ������   (henshan)    /d/henshan/lingxingmen
��ɽ����Ͽ   (hengshan)   /d/hengshan/jinlongxia
����ɽ����   (zhongnan)   /d/quanzhen/shanjiao
����ɽ����   (zhongtiao)  /d/huashan/jzroad3
������ɽ��   (mingjiao)   /d/mingjiao/shanmen
ѩɽ��ɽ��   (xueshansi)  /d/xueshan/shanmen
��ɽɽ·     (xiyu)       /d/xingxiu/tianroad2
����ɽ��     (wuliang)    /d/dali/wuliang/xiaolu1
̫������     (yanziwu)    /d/mr/matou
÷ׯ����     (meizhuang)  /d/meizhuang/gate
���Ʒ�ɽ���� (tiezhang)   /d/tiezhang/shanjiao
��ľ����ʯ�� (heimuya)    /d/heimuya/road1
*/
