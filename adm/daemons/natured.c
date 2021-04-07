//������100����II
//����(lywin)��ǰ�˵�natured.cΪ����������ҹ����ֵķ�����ͨ�档2000/5/30

// natured.c
#include <ansi.h>
#define TIME_TICK (time()*60)
#define TIME_TICK1 (time()*60)
//#define TIME_TICK (time()*60-890000000)
//#define TIME_TICK1 (time()*60-900000000)
//#define TIME_TICK ((time()-900000000)*24)
//#define TIME_TICK1 ((time()-900000000)*24)
nosave int current_day_phase, current_month;
nosave string ppl;
mapping *day_phase;
string  zuji(string str);
string *month_desc = ({
	"��¡����:",
	"��������:",
	"��������:",
	"���紺��:",
	"��������:",
	"�����ġ�:",
	"��ʢ�ġ�:",
	"�����ġ�:",
	"�����:",
	"�����:",
	"�����:",
	"��������:",
});

string *weather_msg = ({
        "�������������",
        "���䵭�����Ʋ�ױ�������ʵ����",
        "�����������Ʈ��Ʈȥ",
        "�����Ʋ�ѻ������",
        "����������ܲ�",
});
mapping *where=({
        (["party":        "������",
        "where" :         "/d/shaolin/guangchang2",]),
        (["party":      "�䵱��",
        "where" :       "/d/wudang/guangchang",]),
        (["party":       "���չ�",
        "where" :       "/d/lingjiu/dating",]),
        (["party":       "��ɽ��",
        "where" :       "/d/huashan/qunxianguan",]),
        (["party":       "ؤ��",
         "where" :       "/d/city/pomiao",]),
         (["party":       "����μ�",
         "where" :       "/d/dali/wfdating",]),
       (["party":       "��Ĺ��",
         "where" :       "/d/gumu/qianting",]),
              (["party":       "������",
         "where" :       "/d/xingxiu/xxh2",]),
               (["party":       "������",
         "where" :       "/d/shenlong/dating",]),
               (["party":       "��ң��",
         "where" :       "/d/xiaoyao/qingcaop",]),
               (["party":       "���ư�",
         "where" :       "/d/tiezhang/wztang",]),
                (["party":       "������",
         "where" :       "/d/kunlun/guangchang",]),
               (["party":       "�һ���",
         "where" :       "/d/taohua/dating",]),
              (["party":       "����ɽ��",
         "where" :       "/d/baituo/dating",]),
               (["party":       "ѩɽ��",
         "where" :       "/d/xueshan/dadian",]),
               (["party":       "ȫ���",
         "where" :       "/d/quanzhen/datang1",]),
                (["party":       "����Ľ��",
         "where" :       "/d/mr/yanziwu",]),
                (["party":       "������",
         "where" :       "/d/lingxiao/dadian",]),
                (["party":       "�嶾��",
         "where" :       "/d/wudujiao/dating",]),
                (["party":       "����",
         "where" :       "/d/tangmen/liujiantang",]),
                (["party":       "����������",
         "where" :       "/d/feitian/daochang",]),
                (["party":       "����",
         "where" :       "/d/tangmen/liujiantang",]),
                (["party":       "������",
         "where" :       "/d/hainan/jingtang",]),
                (["party":       "���͵�",
         "where" :       "/d/xiakedao/shiroom24",]),
                (["party":       "�����",
         "where" :       "/d/xibei/kongdong/xuanyuan_gong",]),
                (["party":       "÷ׯ",
         "where" :       "/d/meizhuang/xiaowu",]),
                (["party":       "������",
         "where" :       "/d/jinghai/jhd19",]),
                (["party":       "�컨��",
         "where" :       "/d/huizhu/zongduo",]),
                (["party":       "�����",
         "where" :       "/d/qingcheng/qiandian",]),
                (["party":       "̩ɽ��",
         "where" :       "/d/taishan/riguan",]),
                (["party":       "��ɽ��",
         "where" :       "/d/songshan/chanyuan",]),
                (["party":       "��ɽ��",
         "where" :       "/d/henshan/zhurongdian",]),
                (["party":       "��ɽ��",
         "where" :       "/d/hengshan/baiyunan",]),
                (["party":       "�������",
         "where" :       "/d/zhongzhou/miaojia_houting",]),
                (["party":       "�������",
         "where" :       "/d/guanwai/xiaowu",]),
                (["party":       "�㵴��",
         "where" :       "/d/yandang/luoyan6",]),

 });
mapping *read_table(string file);
void init_day_phase();

void create()
{
//        day_phase = read_table("/adm/etc/nature/day_phase");
//        init_day_phase();
	string get_month, get_day;
	mixed *local;
	local = localtime(TIME_TICK1);
        get_day = CHINESE_D->chinese_number(local[3]);
	get_month = CHINESE_D->chinese_number(local[4]);
	switch(get_month)
	{
		//spring weather
		case "��":
		case "��":
		case "��":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/spring_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/spring_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/spring_wind");
			   break;
		     }
		     break;
		//summer weather
		case "��":
		case "��":
		case "��":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/summer_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/summer_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/summer_wind");
			   break;
		     }
		     break;
		//autumn weather
		case "��":
		case "ʮ":
		case "ʮһ":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/autumn_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/autumn_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/autumn_wind");
			   break;
		     }
		     break;
		//winter weather
                case "��":
		case "��":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		case "һ":
		        if(get_day=="һ")
		      { day_phase = read_table("/adm/etc/nature/spring");break;}
		      else switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }

		     break;
		default:
		     day_phase = read_table("/adm/etc/nature/day_phase");
	}


	init_day_phase();
}
/*
void init_day_phase()
{
        mixed *local;
        int i, t;

        // Get minutes of today.
        local = localtime(TIME_TICK1);
        t = local[2] * 60 + local[1];           // hour * 60 + minutes

        // Find the day phase for now.
        for( i=0; i < sizeof(day_phase); i++)
                if( t >= day_phase[i]["length"] )
                        t -= (int)day_phase[i]["length"];
                else
                        break;

        current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);

        // Since in our time scale, 1 minute == 1 second in RL, so we don't need
        // any conversion before using this number as call_out dalay, if you
        // changed the time scale, be sure to convert it.

        call_out("update_day_phase",
      (int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}*/
void init_day_phase()
{
	mixed *local;
	int i, t;


	local = localtime(TIME_TICK1);
	t = local[2] * 60 + local[1];


	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else
			break;

	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);
	current_month = local[4];


	remove_call_out("init_day_phase");
	call_out("init_day_phase", 180);


	remove_call_out("update_day_phase");



	call_out("update_day_phase",
	(int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}

void update_day_phase()
{
	int j,i;
	object where, ob, *ob_list;
        remove_call_out("update_day_phase");

        current_day_phase = (++current_day_phase) % sizeof(day_phase);
        switch (day_phase[current_day_phase]["outcolor"])
        {
              case "BLK":
                   message("channel:chat", HIG"�����⡿"BLK + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "RED":
                   message("channel:chat", HIG"�����⡿"RED + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIR":
                   message("channel:chat", HIG"�����⡿"HIR + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "GRN":
                   message("channel:chat", HIG"�����⡿"GRN + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIG":
                   message("channel:chat", HIG"�����⡿"HIG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "YEL":
                   message("channel:chat", HIG"�����⡿"YEL + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIY":
                   message("channel:chat", HIG"�����⡿"HIY + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "BLU":
                   message("channel:chat", HIG"�����⡿"BLU + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIB":
                   message("channel:chat", HIG"�����⡿"HIB + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "MAG":
                   message("channel:chat", HIG"�����⡿"MAG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIM":
                   message("channel:chat", HIG"�����⡿"HIM + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "CYN":
                   message("channel:chat", HIG"�����⡿"CYN + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIC":
                   message("channel:chat", HIG"�����⡿"HIC + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "WHT":
                   message("channel:chat", HIG"�����⡿"WHT + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIW":
                   message("channel:chat", HIG"�����⡿"HIW + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              default:
                   message("channel:chat", HIG"�����⡿"HIG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
        }
//        message("outdoor:vision", day_phase[current_day_phase]["time_msg"] + "\n", users());
        if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
            call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

        call_out("update_day_phase", day_phase[current_day_phase]["length"]);
    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
if(!ob->query_temp("hdjoblb")) continue;
if(!ob->query_temp("hdjobtg")) continue;
if(!environment(ob)) continue;
    j++;
    }
    if (j<38) call_out("give_gift", random(5)+1,"/clone/money/gold",1,"test");
}

void test_robot()
{
	object *obs = users(), ob, robot;
    int i = sizeof(obs), j = 10;

	if (i < 1) return;
	while (j--) {
		ob = obs[random(i)];
		if (wiz_level(ob)) continue;
		if (!living(ob)) continue;
		if (!interactive(ob)) continue;
                if (query_idle(ob) > 30) continue;
		if (!environment(ob)) continue;
		break;
	}
	if (j < 0) return;
	ppl = ob->query("id");
        if (!ob->is_fighting()
        && interactive(ob) && living(ob)
        || ob->query("combat_exp")> 1000000 )
        ob->set_temp("testrobot",1);
        call_out("ok_robot", 1, ob);
}

void ok_robot(object ob)
{
if (ob)
{
ob->set_temp("testrobot",0);
ob->delete_temp("testrobot");
}
}

void event_morning()
{
	object badguy;
	object room;
        if (random(12) == 1)
        {
		if(objectp(room=load_object("/d/city/guangchang")) &&
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
  message("channel:chat", HIY"����͢������"HIR + "�����ݳ��з����ձ���ϸ��\n"NOR,users() );
	}
        if (random(12) == 2)
        {
		if(objectp(room=load_object("/d/city2/di_anmen")) &&
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
  message("channel:chat", HIY"����͢������"HIM + "�ڱ������з����ձ���ϸ��\n"NOR,users() );
	}
        if (random(12) == 3)
        {
		if(objectp(room=load_object("/d/city3/guangchang")) &&
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
 message("channel:chat", HIY"����͢������"HIM + "�ڳɶ����з����ձ���ϸ��\n"NOR,users() );
	}
        if (random(12) == 4)
        {
		if(objectp(room=load_object("/d/quanzhen/zhongxin")) &&
		objectp(badguy = new("/quest/weiguo/jinbing/jin4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
  message("channel:chat", HIB"����͢������"GRN + "���书���з��ֽ����ϸ��\n"NOR,users() );
	}
        if (random(12) == 5)
        {
		if(objectp(room=load_object("/d/dali/taihejiekou")) &&
		objectp(badguy = new("/quest/weiguo/jinbing/jin4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
message("channel:chat", HIB"����͢������"GRN + "�ڴ�����з��ֽ����ϸ��\n"NOR,users() );
	}
        if (random(12) == 6)
        {
		if(objectp(room=load_object("/d/foshan/street3")) &&
		objectp(badguy = new("/quest/weiguo/jinbing/jin4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
message("channel:chat", HIB"����͢������"GRN + "�ڷ�ɽ���з��ֽ����ϸ��\n"NOR,users() );
	}
        if (random(12) == 7)
        {
		if(objectp(room=load_object("/d/fuzhou/dongjiekou")) &&
		objectp(badguy = new("/quest/weiguo/menggu/mengu4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
  message("channel:chat", HIG"����͢������"CYN + "�ڸ��ݳ��з����ɹż�ϸ��\n"NOR,users() );
	}
        if (random(12) == 8)
        {
		if(objectp(room=load_object("/d/hangzhou/road13")) &&
		objectp(badguy = new("/quest/weiguo/menggu/mengu4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
  message("channel:chat", HIG"����͢������"CYN + "�ں��ݳ����з����ɹż�ϸ��\n"NOR,users() );
	}
        if (random(12) == 9)
        {
		if(objectp(room=load_object("/d/lingzhou/center")) &&
		objectp(badguy = new("/quest/weiguo/menggu/mengu4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
  message("channel:chat", HIG"����͢������"CYN + "�����ݳ����з����ɹż�ϸ��\n"NOR,users() );
	}
        if (random(12) == 10)
        {
		if(objectp(room=load_object("/d/quanzhou/zhongxin")) &&
		objectp(badguy = new("/quest/weiguo/xixiabing/xixia4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
  message("channel:chat", HIR"����͢������"BLU + "��Ȫ�ݳ��з������ļ�ϸ��\n"NOR,users() );
	}
        if (random(12) == 11)
        {
		if(objectp(room=load_object("/d/suzhou/baodaiqiao")) &&
		objectp(badguy = new("/quest/weiguo/xixiabing/xixia4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
  message("channel:chat", HIR"����͢������"BLU + "�����ݳ��з������ļ�ϸ��\n"NOR,users() );
	}
        if (random(12) == 12)
        {
		if(objectp(room=load_object("/d/xiangyang/guangchang")) &&
		objectp(badguy = new("/quest/weiguo/xixiabing/xixia4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
  message("channel:chat", HIR"����͢������"BLU + "���������з������ļ�ϸ��\n"NOR,users() );
	}
        if (random(16) == 1)
        {
		if(objectp(room=load_object("/d/huanghe/yongdeng")) &&
		objectp(badguy = new("/quest/weiguo/xixiabing/xixia3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
                message("channel:chat", HIR"��ǰ�߸漱��"HIW + "���Ĵ�����������ľ����������ǣ�\n"NOR,users() );
	}
        if (random(16) == 2)
        {
		if(objectp(room=load_object("/d/quanzhou/zhongxin")) &&
		objectp(badguy = new("/quest/weiguo/japan/japan3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
  message("channel:chat", HIR"��ǰ�߸漱��"HIW + "���ܴ����Ȫ�ݸ�����½��ɱ�Ұ���!!\n"NOR,users() );
	}
        if (random(16) == 4)
        {
		if(objectp(room=load_object("/d/xiangyang/eastgate1")) &&
		objectp(badguy = new("/quest/weiguo/menggu/mengu3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
               message("channel:chat", HIR"��ǰ�߸漱��"HIW + "�ɹŴ�����������������������漱!!\n"NOR,users() );
	}
        if (random(16) == 7)
        {
		if(objectp(room=load_object("/d/city2/di_anmen.")) &&
		objectp(badguy = new("/quest/weiguo/jinbing/jin3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
  message("channel:chat", HIR"��ǰ�߸漱��"HIW + "��������ϵĲ���ɱ���˾��ǣ����Ǹ�Σ!!\n"NOR,users() );
	}
}

void event_night()
{
	object badguy;
	object room;
        if (random(12) == 1)
        {
		if(objectp(room=load_object("/d/city/guangchang")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "���ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 2)
        {
		if(objectp(room=load_object("/d/city2/di_anmen")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "�������н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 3)
        {
		if(objectp(room=load_object("/d/city3/guangchang")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "�ɶ����н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 4)
        {
		if(objectp(room=load_object("/d/quanzhen/zhongxin")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "�书���н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 5)
        {
		if(objectp(room=load_object("/d/dali/taihejiekou")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "������н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 6)
        {
		if(objectp(room=load_object("/d/foshan/street3")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "��ɽ���н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 7)
        {
		if(objectp(room=load_object("/d/fuzhou/dongjiekou")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "���ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 8)
        {
		if(objectp(room=load_object("/d/hangzhou/road13")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "���ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 9)
        {
		if(objectp(room=load_object("/d/lingzhou/center")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "���ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 10)
        {
		if(objectp(room=load_object("/d/quanzhou/zhongxin")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "Ȫ�ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 11)
        {
		if(objectp(room=load_object("/d/suzhou/baodaiqiao")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "���ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 12)
        {
		if(objectp(room=load_object("/d/xiangyang/guangchang")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "�������н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}

}

void event_afternoon()
{
	object *ob_list;
	int i;
	ob_list = children("/quest/weiguo/japan/japan1");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/japan/japan2");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/japan/japan3");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/japan/japan4");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�����Ҳ�����ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/jinbing/jin1");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/jinbing/jin2");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/jinbing/jin3");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/jinbing/jin4");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�����Ҳ�����ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu1");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu2");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu3");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu4");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�����Ҳ�����ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia1");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia2");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia3");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia4");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�����Ҳ�����ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
}

void event_dawn()
{
	object *ob_list;
	int i;
	ob_list = children("/quest/feizei/feizei");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
			message_vision("$NЦ���������ˣ�����Ҳ�����ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
}

void event_midnight()
{
        string get_month, get_day;
        get_day = CHINESE_D->chinese_monthday(TIME_TICK1);
        get_month = CHINESE_D->chinese_month(TIME_TICK1);
        switch(get_month)
        {
                //spring weather
                case "��":
                case "��":
                case "��":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/spring_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/spring_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/spring_wind");
                           break;
                     }
                     break;
                //summer weather
                case "��":
                case "��":
                case "��":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/summer_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/summer_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/summer_wind");
                           break;
                     }
                     break;
                //autumn weather
                case "��":
                case "ʮ":
                case "ʮһ":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/autumn_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/autumn_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/autumn_wind");
                           break;
                     }
                     break;
                //winter weather
                case "ʮ��":
                case "һ":
                case "��":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/winter_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/winter_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/winter_wind");
                           break;
                     }
                     break;
                default:
                     day_phase = read_table("/adm/etc/nature/day_phase");
        }
//        switch(get_day)
//        {
//                case "һ��һ��":
//                     day_phase = read_table("/adm/etc/nature/spring");
//                     break;
//                case "��������":
//                case "��������":
//                case "����ʮ����":
//                case "���¾���":
//                case "ʮ���°���":
//        }
}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase

void event_noon()
{
        object *ob;
        int i, skill,con,con1,con2,con3;
        string get_month,ill,msg;
        get_month = CHINESE_D->chinese_month(TIME_TICK1);
        switch(get_month)
        {
                case "��":
                case "��":
                case "��":
                     ill = "ill_kesou";
                     msg = HIG + "��Ȼ��ͷһ���������о��ƺ�Ҫ�����ˡ�\n" + NOR;
                     break;
                case "��":
                case "��":
                case "��":
                     ill = "ill_zhongshu";
                     msg = HIG+"ͻȻ������֮��һ���ڣ��������ˡ�\n" + NOR;
                     break;
                case "��":
                case "ʮ":
                case "ʮһ":
                     ill = "ill_shanghan";
                     msg = HIG+"��������˸���ս��ͷ������ģ�����˺����ˡ�\n"+NOR;
                     break;
                case "ʮ��":
                case "һ":
                case "��":
                     ill = "ill_dongshang";
                     msg = HIG+"��֫��ĩ��һ��ֱ�������㱻�����ˡ�\n"+NOR;
                     break;
        }
        if(random(2))
        {
                ill = "ill_fashao";msg = HIG+"��ż�з纮����������������\n"+NOR;
        }
        ob = users();
        for(i=0; i<sizeof(ob); i++)
        {
                if( !environment(ob[i]) ) continue;
                if( !environment(ob[i])->query("outdoors") ) continue;
                if( ob[i]->query("age")==14 ) continue;
                con1 = ob[i]->query("qi");
                con2 = ob[i]->query("max_qi");
                (int)con = con1/con2*50;//�γɵ�һ�������ж�����
                con3 = ob[i]->query("neili");
                con2 = ob[i]->query("max_neili");
		if( con2 == 0) con2 = 1;
                (int)con1 = con3/con2*50;//�γɵڶ��������ж�����
                if(random(con)+random(50)+random(con1)<25)
                {
                        ob[i]->apply_condition(ill, 10);
                        tell_object(ob[i], msg);
                }
        }
}

string outdoor_room_description()
{
	return "    " + sprintf(
		day_phase[current_day_phase]["desc_msg"],
		month_desc[current_month]) + "��\n";
}
string outdoor_room_outcolor()
{
        return day_phase[current_day_phase]["outcolor"];
}

string game_time()
{
        return CHINESE_D->chinese_date(TIME_TICK1);
}

mapping *read_table(string file)
{
        string *line, *field, *format;
        mapping *data;
        int i, rn, fn;

        line = explode(read_file(file), "\n");
        data = ({});
        for(i=0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !pointerp(field) ) {
                        field = explode( line[i], ":" );
                        continue;
                }
                if( !pointerp(format) ) {
                        format = explode( line[i], ":" );
                        continue;
                }
                break;
        }

        for( rn = 0, fn = 0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
                sscanf( line[i], format[fn], data[rn][field[fn]] );
                fn = (++fn) % sizeof(field);
                if( !fn ) ++rn;
        }
        return data;
}

void give_gift(string gift, int amount, string msg)
{
        int i,combatexp,rd,j,num,factor,timep,sl;
        object ob;
        object env,room2;
        object *players;
        string room;
        string *dir2;
        string file;
string *roomlines;
string location,local,fname;
mapping quest,item,npc,quests;
mapping target;
string envn;
object newob, *ob_list;
        string tag = "2000000";
        string *levels = ({
                        "10000",
                        "15000",
                        "20000",
                        "30000",
                        "50000",
                        "80000",
                        "100000",
                        "130000",
                        "170000",
                        "220000",
                        "300000",
                        "450000",
                        "600000",
                        "800000",
                        "1000000",
                  });
tag = "10000";
if (random(2)==1) tag="15000";
if (random(3)==1) tag="20000";
if (random(4)==1) tag="30000";
if (random(5)==1) tag="50000";
if (random(6)==1) tag="80000";
if (random(7)==1) tag="100000";
if (random(8)==1) tag="130000";
if (random(9)==1) tag="170000";
if (random(10)==1)tag="220000";
if (random(11)==1)tag="300000";
if (random(12)==1)tag="450000";
if (random(13)==1)tag="600000";
if (random(14)==1)tag="800000";
if (random(15)==1)tag="1000000";
if (random(16)==1)tag="2000000";
        players = users();
        if (sizeof(players) >= 3)
        {
                for (i = 0; i < 3; i++)
                {
                        ob = players[random(sizeof(players))];
                        if (wizardp(ob)) continue;
                        if (ob->query_temp("hdjoblb")) continue;
                        env = environment(ob);
                        if (!env) continue;
                        while (env && env->is_character())
                                env = environment(env);
                        if (env) break;

                }
//                if (i >= 3) return;

                //if (objectp(env))
                //        tell_room(env, msg);
                //for (i = 0; i < amount; i++)
                //{
                //        ob = new(gift);
                //       ob->move(env);
                //}
if (objectp(env))
{
dir2=explode(base_name(env),"/");
room=zuji(dir2[1])+env->query("short");
combatexp = (int) (ob->query("combat_exp"));
rd=random(6);
//rd=5;
//CHANNEL_D->do_channel( this_object(), "rumor", "��һ�������:"+ob->name()+"����"+rd+"��\n");

        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
             combatexp=combatexp/4;
             if( atoi(levels[j])  <= combatexp )
             {
                   num=j;
                   factor=10;
                   break;
             }
        }
        if (num>0)
        {
             if (random(50)>45)
             {
                   num=num-1;
             }
        }
        else
        {
             if ((num<sizeof(levels)-1)&&(random(100)>95))
             {
                   num=num+1;
                   factor=15;
             }
        }
        tag=levels[num];

if (rd==0)
{
        if (random(2) == 0 )
     quest = QUESTS_D(tag)->query_quest();
       else
     quest = QUESTH_D(tag)->query_quest();
        timep = quest["time"];
        if (!quest["time"]) timep=600;
        timep = timep+360;

if (quest["quest"])
{
ob->set_temp("hdjoblb","�ͻ�");
ob->set_temp("hdjobtg",quest["quest"]);
ob->set_temp("hdjobsc","�ͻ�:"+quest["quest_city"]+"��"+quest["quest"]);
CHANNEL_D->do_channel( this_object(), "rumor", "��˵:"+ob->name()+"��������Ҫ�͵�"+quest["quest_city"]+"��"+quest["quest"]+"���ϡ�\n");
}
}

if (rd==4)
{

ob->set_temp("hdjoblb","����");
ob->set_temp("hdjobtg","����");
ob->set_temp("hdjobsc","��һ�������");
CHANNEL_D->do_channel( this_object(), "rumor", "��˵:"+ob->name()+"�и�����Ҫ�͸�ĳ����ҡ�\n");

}

if (rd==5)
{
target=where[random(sizeof(where))];
room2=load_object(target["where"]+".c");
if (room2)
{
local=room2->query("short");
if (local)
{
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
ob->set_temp("hdjoblb","����");
ob->set_temp("hdjoben",local);
ob->set_temp("hdjobtg",target["where"]+".c");
ob->set_temp("hdjobsc","�����ڵ����������"+target["party"]+"��"+room);
CHANNEL_D->do_channel( this_object(), "rumor", ob->query("name")+"��˵�����ڵ�����Ҫ����"+target["party"]+HIM"��\n");
}
}

}

if (rd==1)
{
quest = QUESTW_D(tag)->query_quest();
        timep = quest["time"];
        if (!quest["time"]) timep=600;
        timep = timep+360;

if (quest["quest"])
{
ob->set_temp("hdjoblb","Ѱ��");
ob->set_temp("hdjobtg",quest["quest"]);
ob->set_temp("hdjobsc","Ѱ��:"+quest["quest_city"]+"��"+quest["quest"]);
CHANNEL_D->do_channel( this_object(), "rumor", "��˵:"+ob->name()+"��Ҫ�ҵ�"+quest["quest_city"]+"��"+quest["quest"]+"��\n");
}
}
if (rd==2)
{
seteuid(geteuid(this_object()));
file = read_file("/clone/medicine/dynamic_location");
	if (ob->query("combat_exp",1)<=2000000)
	file = read_file("/clone/medicine/dynamic_location1");
	else if (ob->query("combat_exp",1)<=4000000)
	file = read_file("/clone/medicine/dynamic_location2");
	else if (ob->query("combat_exp",1)<=6000000)
	file = read_file("/clone/medicine/dynamic_location3");
else if (ob->query("combat_exp",1)<=8000000)
	file = read_file("/clone/medicine/dynamic_location4");
else if (ob->query("combat_exp",1)>8000000)
	file = read_file("/clone/medicine/dynamic_location5");
if (!file)
	file = read_file("/clone/medicine/dynamic_location");

roomlines = explode(file,"\n");
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
if (!room2)
{
	file = read_file("/clone/medicine/dynamic_location");
	roomlines = explode(file,"\n");
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
}
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
//ob->apply_condition("roomjob",10);
//ob->set_temp("roomjob",local);
ob->set_temp("hdjoblb","��̽");
ob->set_temp("hdjobtg",local);
ob->set_temp("hdjobsc","��̽:"+room);
CHANNEL_D->do_channel( this_object(), "rumor", "��˵:"+ob->name()+"��Ҫ�õ�"+room+"���鱨��\n");
//tell_object(ob,"����:��"+room+"ȥ��̽һ�����(citan)��\n" NOR);
//CHANNEL_D->do_channel( this_object(), "rumor", "����3��\n");
//CHANNEL_D->do_channel( this_object(), "rumor", "����3:��"+room+"ȥ��̽һ�����(citan)��\n");
//	  tell_object(ob,HIC"����ʹ˵:����˵�ڡ�"HIR+room+HIC"����������һЩ�����¼���"+
//           "��Ͽ�ȥ��"HIR+local+HIC"����̽(citan)һ�°ɡ�\n"NOR);
//if (wizardp(ob))
//	  tell_object(ob,GRN"WIZ��Ϣ:��̽λ�á�"YEL+fname+GRN"����\n"NOR);
}

if (rd==3)
{
seteuid(geteuid(this_object()));
file = read_file("/clone/medicine/dynamic_location");
	if (ob->query("combat_exp",1)<=2000000)
	file = read_file("/clone/medicine/dynamic_location1");
	else if (ob->query("combat_exp",1)<=4000000)
	file = read_file("/clone/medicine/dynamic_location2");
	else if (ob->query("combat_exp",1)<=6000000)
	file = read_file("/clone/medicine/dynamic_location3");
else if (ob->query("combat_exp",1)<=8000000)
	file = read_file("/clone/medicine/dynamic_location4");
else if (ob->query("combat_exp",1)>8000000)
	file = read_file("/clone/medicine/dynamic_location5");
if (!file)
	file = read_file("/clone/medicine/dynamic_location");

roomlines = explode(file,"\n");
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
if (!room2)
{
	file = read_file("/clone/medicine/dynamic_location");
	roomlines = explode(file,"\n");
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
}
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
//ob->apply_condition("roomjob",10);
//ob->set_temp("roomjob",local);
ob->set_temp("hdjoblb","��ɱ");
ob->set_temp("hdjobtg",location);
ob->set_temp("hdjobsc","��ɱ:"+room);
CHANNEL_D->do_channel( this_object(), "rumor", "��˵:"+ob->name()+"��һ�������"+room+"�������֡�\n");
}
}
sl=random(3);
if (sl==0)
{
   ob_list = users();
    newob = ob_list[random(sizeof(ob_list))];
if(newob->query("combat_exp",1)<100000 || !newob->query_temp("hdjob2tg") || !newob->query_temp("nhdjob2tg")) newob = ob_list[random(sizeof(ob_list))];
if(newob->query("combat_exp",1)<100000 || !newob->query_temp("hdjob2tg") || !newob->query_temp("nhdjob2tg")) newob = ob_list[random(sizeof(ob_list))];
if(newob->query("combat_exp",1)<100000 || !newob->query_temp("hdjob2tg") || !newob->query_temp("nhdjob2tg")) newob = ob_list[random(sizeof(ob_list))];

if(wizardp(newob) || newob->query("combat_exp",1)<100000) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("combat_exp",1)<100000) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("age")<=19) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("age")<=19) newob = ob_list[random(sizeof(ob_list))];

if (newob)
{
env=environment(newob);
if (env)
{
dir2=explode(base_name(env),"/");
envn=zuji(dir2[1])+"-"+env->query("short");
}
if (newob && envn)
{
newob->set_temp("hdjoblb","��ս");
newob->set_temp("hdjobtg",newob->query("id"));
newob->set_temp("hdjobsc","��ս"+newob->name());
CHANNEL_D->do_channel( this_object(), "rumor", "��˵:����������ս��"+envn+"������:"+newob->name()+"��\n");
}
}
}

if (sl==1)
{
quest = QUESTS_D(tag)->query_quest();
if (random(2) == 0 ) quest = QUESTH_D(tag)->query_quest();
if (quest["quest"])
{
   ob_list = users();
    newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("combat_exp",1)<100000) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("combat_exp",1)<100000) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("age")<=19) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("age")<=19) newob = ob_list[random(sizeof(ob_list))];
if (newob)
{
env=environment(newob);
if (env)
{
dir2=explode(base_name(env),"/");
envn=zuji(dir2[1])+"-"+env->query("short");
}
if (newob && envn && newob->query("age",1)>=20)
{
newob->set_temp("ishm",0);
newob->delete_temp("ishm");
newob->set_temp("hdjoblb","����");
newob->set_temp("hdjobtg",quest["quest"]);
newob->set_temp("hdjobsc","����:"+quest["quest_city"]+"��"+quest["quest"]+"���һ��"+newob->name()+"��");
CHANNEL_D->do_channel( this_object(), "rumor", "��˵"+quest["quest_city"]+"��"+quest["quest"]+"���һ��"+newob->name()+"��\n");
}
}
}
}

if (random(8)==6)
{

seteuid(geteuid(this_object()));
file = read_file("/clone/medicine/map1");
if (random(2)==0) file = read_file("/clone/medicine/map4");

if (!file)
	file = read_file("/clone/medicine/map1");

roomlines = explode(file,"\n");
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
if (!room2)
{
	file = read_file("/clone/medicine/map1");
	roomlines = explode(file,"\n");
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
}
local=room2->query("short");
if (local)
{
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
ob->set_temp("hdjoblb","����");
ob->set_temp("hdjobtg",local);
ob->set_temp("hdjobsc","����:�и�����������"+room);
CHANNEL_D->do_channel( this_object(), "rumor", ob->name()+"��˵�и�����׷ɱ�Ķ���������"+room+"������\n");

}
}

        }
}



string  zuji(string str)
{
string output;
      	if (str=="baituo")

	output="����ɽ��";

if (str=="binghuodao")

	output="���𵺵�";

if (str=="city")

	output="���ݵ�";

if (str=="city2" || str=="beijing"  || str=="huanggon"  || str=="huanggong" || str=="beihai")

	output="�����ǵ�";

if (str=="city4" || str=="changan")

	output="�����ǵ�";

if (str=="dali")

	output="�����";

if (str=="emei")

	output="��üɽ��";

if (str=="foshan")

	output="��ɽ��";

if (str=="gaibang")

	output="ؤ���";

if (str=="gaochang")

	output="�߲��Թ���";

if (str=="guanwai")

	output="�����";

if (str=="guiyun")

	output="����ׯ��";

if (str=="gumu")

	output="��Ĺ�ɵ�";

if (str=="hangzhou")

	output="���ݵ�";

if (str=="heimuya")

	output="��ľ�µ�";

if (str=="hengshan")

	output="��ɽ��";

if (str=="henshan")

	output="��ɽ��";

if (str=="huanghe")

	output="�ƺӾ�����";

if (str=="huashan")

	output="��ɽ��";

if (str=="jinshe")

	output="����ɽ����";

if (str=="lingjiu")

	output="���չ���";

if (str=="lingzhou")

	output="���ݵ�";

if (str=="meizhuang")

	output="÷ׯ��";

if (str=="mingjiao")

	output="���̵�";

if (str=="qingcheng")

	output="���ɽ��";

if (str=="quanzhen")

	output="ȫ���ɵ�";

if (str=="quanzhou")

	output="Ȫ�ݵ�";

if (str=="shaolin")

	output="�����µ�";

if (str=="shenlong")

	output="��������";

if (str=="songshan")

	output="��ɽ��";

if (str=="suzhou")

	output="���ݵ�";

if (str=="taishan")

	output="̩ɽ��";

if (str=="taohua")

	output="�һ�����";

if (str=="tianlongsi")

	output="�����µ�";

if (str=="wanjiegu")

	output="��ٹȵ�";

if (str=="wudang")

	output="�䵱ɽ��";

if (str=="xiakedao")

	output="���͵���";

if (str=="xiangyang")

	output="�����ǵ�";

if (str=="xiaoyao")

	output="��ң�ֵ�";

if (str=="xingxiu")

	output="���޺���";

if (str=="xueshan")

	output="ѩɽ�µ�";

if (str=="xuedao")

	output="��ѩɽ��";

if (str=="mr")

	output="Ľ�����ҵ�";

if (str=="kunlun")

	output="����ɽ��";

if (str=="tiezhang")

	output="�����ŵ�";

if (str=="huizhu")

	output="���岿���";

if (str=="yinju")

	output="һ�ƴ�ʦ�ӵ�";

if (str=="menggu")

	output="�ɹŲ�ԭ��";

if (str=="qianjin")

	output="����ǧ��¥��";

if (str=="lingshedao")

	output="���ߵ���";

if (str=="ruzhou")

	output="���ݳǵ�";

if (str=="kunming")

	output="������";

if (str=="jingzhou")

	output="���ݵ�";

if (str=="yanjing")

	output="ʢ����";

if (str=="lanzhou" || str=="lanzhouchen")

	output="���ݵ�";

if (str=="jyguan")

	output="�����Ա������ص�";

if (str=="changcheng")

	output="�����Ա����ǵ�";

if (str=="fairyland")

	output="���صĺ�÷ɽׯ";

if (str=="sdxl")

	output="��ħ�������Ĺ";

if (str=="jqg")

	output="�����";

if (str=="nio")

	output="ţ�Ҵ��";

if (str=="feihu")

	output="�������ص�";

if (str=="wuguan")

	output="������ݵ�";

if (str=="village")

	output="��ɽ���";

if (str=="taohuacun")

	output="�һ����";

if (str=="pingan")

	output="ƽ���ǵ�";

if (str=="lingxiao")

	output="�����ǵ�";

if (str=="wudujiao")

	output="�嶾�̵�";

if (str=="hj")

	output="��ɽ����ԭ��";
if (str=="dali/yuxu")

	output="��������۵�";
if (str=="dali/wuliang")

	output="��������ɽ��";
if (str=="huanghe/yyd")

	output="�ƺ�������";
if (str=="kaifeng")

	output="����ǵ�";
if (str=="feitian")

	output="������������";
if (str=="japan")

	output="�ձ��񻧵�";
if (str=="tangmen")

	output="���ŵ�";
if (str=="luoyang")

	output="�����ǵ�";

if (str=="chengdu" || str=="city3")

	output="�ɶ���";

if (str=="baihuagu")

	output="�ٻ��ȵ�";

if (str=="heizhao")

	output="�ٻ��Ⱥ��ӵ�";

if (str=="jiaxing")

	output="���˵�";

if (str=="shiliang")

	output="�¼�ׯ��";

if (str=="wuyi")

	output="����ɽ����";

if (str=="yanping")

	output="��ƽ�ǵ�";


if (str=="jiangling")
{
	output="����ǵ�";
}

if (str=="yueyang")
{
	output="�����ǵ�";
}

if (str=="qilian")
{
	output="����ɽ��";
}

if (str=="shouxihu")
{
	output="��������";
}

if (str=="wuxi")
{
	output="�����ǵ�";
}

if (str=="yixing")
{
	output="���˳ǵ�";
}
if (str=="taiwan")
{
	output="̨���";
}
if (str=="nanyang")
{
	output="������";
}
if (str=="nanshaolin")
{
	output="�����ֵ�";
}

if (str=="cangzhou")
{
	output="���ݵ�";
}

if (str=="tanggu")
{
	output="�����ǵ�";
}

if (str=="yunhe")
{
	output="�����˺ӵ�";
}

if (str=="hainan")
{
	output="���ϵ���";
}

if (str=="jindezheng")
{
	output="�������";
}

if (str=="yandang")
{
	output="�㵴ɽ��";
}

if (str=="jinling")
{
	output="����ǵ�";
}

if (str=="sandboy")
{
	output="����ũ���";
}

if (str=="huangshan")
{
	output="��ɽ��";
}

if (str=="yubifeng")
{
	output="��ʷ��";
}

if (str=="quanzhouchen")
{
	output="Ȫ�ݳ��ڵ�";
}

if (str=="qingzh")
{
	output="��ظ�ԭ";
}

if (str=="changbaishan" || str=="gaoli")
{
	output="���� ����ɽ��";
}

if (str=="annan")
{
	output="���ϸ�����";
}

if (str=="taiyuan")
{
	output="̫ԭ������";
}

if (str=="hefei")
{
	output="�Ϸʸ�����";
}

if (str=="jiujiang")
{
	output="�Ž�������";
}

if (str=="baling")
{
	output="���긽����";
}

if (str=="xinjiang")
{
	output="�½�������";
}
if (str=="dingxiang")
{
	output="���帽����";
}
if (str=="suiye")
{
	output="��Ҷ������";
}


if (str=="mayi")
{
	output="���ر߽�������";
}
if (str=="xuzhou")
{
	output="���ݳǸ�����";
}
if (str=="jinan")
{
	output="���ϳǸ�����";
}
if (str=="guizhou")
{
	output="�����Ǹ�����";
}

if (str=="nanchang")
{
	output="�ϲ��Ǹ�����";
}


if (str=="changsha")
{
	output="��ɳ�Ǹ�����";
}


if (str=="zhongzhou")
{
	output="���ݳǸ�����";
}

if (str=="xizang" || str=="zangbei")
{
	output="���ػ�ر�������";
}

if (str=="tianshui")
{
	output="��ˮ�Ǹ�����";
}

if (str=="datong")
{
	output="��ͬ��������";
}
if (str=="ny")
{
	output="��Զ�Ǹ�����";
}
if (str=="fengtian")
{
	output="ʢ���Ǹ�����";
}

if (str=="yanmen")
{
	output="���Źظ�����";
}
if (str=="cloud")
{
	output="����򸽽���";
}
if (str=="xueting")
{
	output="ѩͤ�򸽽���";
}
if (str=="welcome")
{
	output="�Ŵ帽����";
}
if (!output)
{
	output="δ֪�����";
}

if (output=="")
{
	output="δ֪�����";
}


return output;
}



mapping *query_day_phase() { return day_phase; }
