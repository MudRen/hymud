// more work needed to use this object to make poison
#include <ansi.h>
inherit ITEM;
#define MAX_PAWN 50


void init()
{
        add_action("do_eat2", "mygift");
        add_action("do_eat", "ci");
        add_action("do_eat", "he");
        add_action("do_sleep", "xiuxi");
        add_action("do_xx", "xiuxing");
          add_action ("do_fly","chen");
	add_action("do_pawn", "mpawn");
	add_action("do_redeem", "mredeem");

}

void create()
{
	set_name(YEL"��Ա����"NOR, ({"member beg", "beg"}));
        set("unit", "ֻ");
set("long", YEL"��Աר�ã������濴��ȥ����Զ�Բ���ĸ�����\n
����ԳԺ���Ϣ�˳�,����������(he,ci,xiuxi,chen,xiuxing,��(mpawn)ȡ(mredeem)�����Գ�(chen)��
��վ(dache) �������(majiu) ���ݵ���(dp) ����(gc) ����(tam) Ȫ��(qz)  ����(sz)����ׯ(gyz) 
ʢ��(yj) ���(wg) ����(km) ����(hz)  ����(lz) ����(bl) ���ݳ�(fz) ����(cz) ����(yx) ����(ly)  
����(yy) ����(tg) ��ƽ(yp) ����(jl)������(wx) �Ž�(jj) ʢ��(sj)   ��Զ(ny) ��ɳ(cs) �ϲ�(nc)
����(gy) �½�(xj) ����(xz) ����(xiz) ̫ԭ(ty) �Ϸ�(hf) �ձ�(jp) ����(an) ����(cx)   ����(nj) 
�书��(wgz)����(yl)����(gw)  ����(dx) ����(ca)   �ɶ�(cd) ����(laz)����(jz) ����(xy)����(dl)
����(shl) ��ɽ(hs) ����(lj) �䵱(wd) ����(mj) ����(sld) ����(xx) ѩɽ(xs) �μ�(mp26)
��ü(em) ȫ��(quz)����ɽ(bt)��Ĺ(gm) ����(mp10)����(mp11)���(mp12)÷ׯ(mp8)����(mp9) �һ�(thd)
�컨(mp1)  ���(mp2)̩ɽ��(mp3)��ɽ(mp4) ��ɽ(mp5)��ɽ(mp6) ���(mp7) Ľ��(mp13) ���� (mp14)
����(mp15) ����(mp16) ����(mp17) ����(mp18) ����(mp19) ����(mp20)  �嶾��(mp21) ��ң(mp22) 
��ػ�(mp23) ������(mp24)������(mp25)\n"NOR      
);
	set("no_get",1);
	set("no_drop",1);
		set("no_get", 1);
		set("no_put", 1);
		set("no_drop", 1);
             set("value", 0);
             set("material", "steel");
             set("no_drop", "�������������뿪�㡣\n");
        setup();
}

int do_eat2()
{
int exp;
object me = this_player();


if (me->is_busy())
return notify_fail("������æ��\n");
if (me->is_fighting())
return notify_fail("�����ڴ�\n");

tell_object(me,YEL "������ľ�����"+me->query("combat_exp",1)+"��\n" NOR);

exp=(int)me->query("combat_exp",1);
if (exp<=80000)
tell_object(me,YEL "�����ʺ������������������"+HIR"chen job1\n"NOR+HIR"ask lao about job\n"+HIR"��ذ���help nbjob\n"NOR);

if (exp>80000 && exp<=180000)
tell_object(me,YEL "�����ʺ����������ĥҩ����"+HIR"chen job2\n"NOR+HIR"ask ping about job\n"+HIR"��ذ���help moyao\n"NOR);

if (exp>=180000 && exp<=300000)
tell_object(me,YEL "�����ʺ����������Ѳ������"+HIR"chen job7\n"NOR+HIR"ask wang about job\n"+HIR"��ذ���help xunchen\n"NOR);

if (exp>80000 && exp<=500000)
tell_object(me,YEL "�����ʺ���������Ƿ�ľ����"+HIR"chen job3\n"NOR+HIR"ask songque about job\n"+HIR"��ذ���help kanshu\n"NOR);

if (exp>=500000 && exp<=1000000)
tell_object(me,YEL "�����ʺ���������ǳ�Ϸ����"+HIR"chen job4\n"NOR+HIR"ask guan about job\n"+HIR"��ذ���help changxi\n"NOR);

if (exp>=180000 && exp<=1500000)
tell_object(me,YEL "�����ʺ���������Ǵ�������"+HIR"chen job5\n"NOR+HIR"south ��ɱ�������ý���\n"+HIR"��ذ���help dalie\n"NOR);

if (exp>=1500000 && exp<=2500000)
tell_object(me,YEL "�����ʺ���������ǲɻ�����"+HIR"chen job8\n"NOR+HIR"ask tian about job\n"+HIR"��ذ���help tianjob\n"NOR);

if (exp>80000 && exp<=2500000)
tell_object(me,YEL "������������ɣ���������������"+HIR"�ҵ����ɵ�������\n"NOR+HIR"����job��duilian ������Ա\n"+HIR"��ذ���help geren\n"NOR);

if (exp>1500000)
tell_object(me,YEL "���Ѿ���һ�������ˣ����ܼ�����Ҫ���������:\n"+HIR"��������:help taskjobs\n"NOR+HIR"��������help geren \n"+HIR"��������help aboutquest\n"NOR);

if (exp>=300000 )
tell_object(me,YEL "���������ȥ�Թ�̽���ˣ�"+HIR"chen job9\n"NOR+"��ذ���help migong\n"NOR);

if (exp>=300000 )
tell_object(me,YEL "���������ȥ��ս�����ˣ�"+HIR"chen job10\n"+HIR"ask bei chou about challenge\n"NOR+"��ذ���help boss ��������-��ս����\n"NOR);

if (exp>2500000)
tell_object(me,YEL "�Ѿ��������ɴ��������ˡ��������ɣ�����ƾ��Ծ��\n"NOR);


me->start_busy(1);
return 1;
}


int do_eat(string arg)
{
object me = this_player();
	if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        if (!me->query("hyvip") && !wizardp(me))
                return notify_fail("�Բ���ֻ�л�Ա�������ܴ˷���\n");

if (me->is_busy())
return notify_fail("������æ��\n");
if (me->is_fighting())
return notify_fail("�����ڴ�\n");

if (me->query("food")*1.5 > me->max_food_capacity()
&& me->query("water")*1.5 > me->max_water_capacity())
return notify_fail("�����ڲ�����!\n");

message_vision(YEL "$N�ó�������Դ����һ��!!\n" NOR,me);
me->set("food",me->max_food_capacity());me->set("water",me->max_water_capacity());
if (me->query("qi") < 50 )
	me->add("qi",30);
if (me->query("jing") < 50 )
	me->add("jing",30);


me->start_busy(8);
}
int do_sleep(string arg)
{
object me = this_player();
	if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        if (!me->query("hyvip") && !wizardp(me))
                return notify_fail("�Բ���ֻ�л�Ա�������ܴ˷���\n");



if (me->is_busy())
return notify_fail("������æ��\n");
if (me->is_fighting())
return notify_fail("�����ڴ�\n");

if (me->query("qi") > me->query("max_qi")
&& me->query("jing") > me->query("max_jing")
)
return notify_fail("�����ڲ�����!\n");
message_vision(YEL "$N�ó���Ա�������ڵ�����Ϣһ��!!\n" NOR,me);
if (me->query("qi") < me->query("eff_qi"))
me->add("qi",me->query("eff_qi")/2);
if (me->query("jing") < me->query("eff_jing"))
me->add("jing",me->query("eff_jing")/2);


if (me->query("eff_qi") < me->query("max_qi"))
me->add("eff_qi",me->query("max_qi")/2);
if (me->query("eff_jing") < me->query("max_jing"))
me->add("eff_jing",me->query("max_jing")/2);
me->set_temp("isnbbg",1);
me->start_busy(6);
return notify_fail("����Ϣ��һ��!\n");
}

  int do_fly(string arg)
{

          string pla;
          object me = this_player();
if( me->query("jing") < 30 )
               return notify_fail("�㾫�񲻹���ʢ��û����������\n");
if( me->query_temp("pending/team"))
               return notify_fail("�����ͱ�������أ�\n");				

        if (!me->query("hyvip") && !wizardp(me))
                return notify_fail("�Բ���ֻ�л�Ա�������ܴ˷���\n");

if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR 
       ||environment(me)->query("magicset")==1
       ||environment(me)->query("maze")
       )
			return notify_fail("�˴��޷�ʹ�ã� ����ȫ�ǵ�·����������һ�ҡ�\n");

/*
if( !environment(me)->query("no_fight") && me->query("combat_exp") > 900000)
{
  message_vision("ֻ���ڰ�ȫ��������ҵ���!!!\n"
                 ,me);
      	return 1;
}

if( !environment(me)->query("no_fight") && me->query("str") > 31)
{
  message_vision("ֻ���ڰ�ȫ��������ҵ���!!!\n"
                 ,me);
      	return 1;
}

if( !environment(me)->query("no_fight") && me->query("zhuanshen"))
{
  message_vision("ֻ���ڰ�ȫ��������ҵ���!!!\n"
                 ,me);
      	return 1;
}
*/

if (me->is_busy())
return notify_fail("������æ��\n");
if (me->is_fighting())
return notify_fail("�����ڴ�\n");

if ( me->query_temp("in_guard")   || me->query_temp("player_working") || me->query_temp("shouwei"))
return notify_fail("������������!\n");
          if (!arg)
              return notify_fail("����ȥ���\n");
          if( !wizardp(me) && me->is_fighting()  ) 
          return notify_fail("��ôΣ�գ��ǻ���ʱ��ȥ����?\n");

          if (me->query_temp("pigging_seat"))
                return notify_fail("���뿪�����������ж���\n");
          if( environment(me)->query("light_up"))
               return notify_fail("�ĳ��ﲻ������!!\n");

//if( !environment(me)->query("outdoors") ) 
//          return notify_fail(HIY"\n�������������\n"NOR);


          else {
          message_vision(HIY
"$N���˸���򣬲���ʾ�����е����ֳ���Ʊ�����ǣ��������\n"+
"$N�����������һ������ඡ���ֻ������ʻ�����ɱ���ȥ������\n\n"NOR, me);
}
          if(arg=="gc") pla = "/d/city/guangchang";
     else if(arg=="xx") pla = "/d/xingxiu/xxh1";
     else if(arg=="mj") pla = "/d/mingjiao/shanmen";
     else if(arg=="em") pla = "/d/emei/qingyinge";
     else if(arg=="shl") pla = "/d/shaolin/guangchang1";
     else if(arg=="lj") pla = "/d/lingjiu/damen";
     else if(arg=="dl") pla = "/d/dali/center";
     else if(arg=="xs") pla = "/d/xueshan/shanmen";
     else if(arg=="wd") pla = "/d/wudang/guangchang";
     else if(arg=="hs") pla = "/d/huashan/zhenyue";
     else if(arg=="tam") pla = "/d/beijing/tian_anm";
     else if(arg=="quz") pla = "/d/quanzhen/damen";
     else if(arg=="bt") pla = "/d/baituo/dating";
     else if(arg=="qz") pla = "/d/quanzhou/zhongxin";
     else if(arg=="gm") pla = "/d/gumu/mumen";
     else if(arg=="sz") pla = "/d/suzhou/canlangting";
     else if(arg=="gyz") pla = "/d/guiyun/taihu";
     else if(arg=="xy") pla = "/d/xiangyang/guangchang";
     else if(arg=="ca") pla = "/d/changan/ca";
     else if(arg=="cd") pla = "/d/chengdu/guangchang";
     else if(arg=="laz") pla = "/d/lanzhou/guangchang";
     else if(arg=="jz") pla = "/d/jingzhou/guangchang";
     else if(arg=="km") pla = "/d/kunming/jinrilou";
     else if(arg=="yj") pla = "/d/yanjing/street";               
     else if(arg=="wg") pla = "/d/wuguan/guanmen";
     else if(arg=="hz") pla = "/d/hangzhou/kedian";
     else if(arg=="lz") pla = "/d/lingzhou/center";
     else if(arg=="dache") pla = "/d/city/kedian";
     else if(arg=="majiu") pla = "/d/city/majiu";
     else if(arg=="wm") pla = "/d/city/wumiao";
     else if(arg=="dp") pla = "/d/city/dangpu2";
     else if(arg=="fz") pla = "/d/fuzhou/majiu";							
else if(arg=="cz") pla = "/d/cangzhou/beimen";									     
else if(arg=="yx") pla = "/d/yixing/yixing";									
else if(arg=="tg") pla = "/d/tanggu/beimen";									
else if(arg=="ly") pla = "/d/luoyang/center";									
else if(arg=="yy") pla = "/d/yueyang/guangchang";		
else if(arg=="wgz") pla = "/d/quanzhen/guchang";			
else if(arg=="yp") pla = "/d/yanping/majiu";			
else if(arg=="jl") pla = "/d/jiangling/beimen";	
else if(arg=="wx") pla = "/d/wuxi/majiu";						
else if(arg=="yl") pla = "/d/xingxiu/majiu";
else if(arg=="gw") pla = "/d/guanwai/nancheng";
else if(arg=="ty") pla = "/d/taiyuan/xidajie1";
else if(arg=="sj") pla = "/d/fengtian/cross";
else if(arg=="ny") pla = "/d/ny/postoffice";
else if(arg=="cs") pla = "/d/changsha/guangchang";
else if(arg=="nc") pla = "/d/nanchang/center";
else if(arg=="gy") pla = "/d/guizhou/center";
else if(arg=="xj") pla = "/d/xinjiang/nanmen";
else if(arg=="xz") pla = "/d/xuzhou/xidajie";
else if(arg=="xiz") pla = "/d/xizang/citygate";
else if(arg=="thd") pla = "/d/taohua/haitan";
else if(arg=="sld") pla = "/d/shenlong/haitan";
else if(arg=="jp") pla = "/d/japan/haigang";
else if(arg=="an") pla = "/d/annan/matou";
else if(arg=="cx") pla = "/d/gaoli/gangkou";
else if(arg=="hf") pla = "/d/hefei/xidajie3";
else if(arg=="jj") pla = "/d/jiujiang/dongdajie2";
else if(arg=="bl") pla = "/d/baling/dongdajie1";
else if(arg=="dx") pla = "/d/dingxiang/beidajie1";

else if(arg=="mp1") pla = "/d/huizhu/zongduo";
else if(arg=="mp2") pla = "/d/qingcheng/qiandian";
else if(arg=="mp3") pla = "/d/taishan/riguan";
else if(arg=="mp4") pla = "/d/songshan/chanyuan";
else if(arg=="mp5") pla = "/d/henshan/zhurongdian";
else if(arg=="mp6") pla = "/d/hengshan/baiyunan";
else if(arg=="mp7") pla = "/d/zhongzhou/miaojia_houting";
else if(arg=="mp8") pla = "/d/meizhuang/xiaowu";
else if(arg=="mp9") pla = "/d/jinghai/jhd19";
else if(arg=="mp10") pla = "/d/hainan/jingtang";
else if(arg=="mp11") pla = "/d/xiakedao/shiroom24";
else if(arg=="mp12") pla = "/d/xibei/kongdong/xuanyuan_gong";
else if(arg=="mp13") pla = "/d/mr/yanziwu";
else if(arg=="mp14") pla = "/d/tangmen/dating";
else if(arg=="mp15") pla = "/d/heimuya/chengdedian";
else if(arg=="mp16") pla = "/d/lingxiao/dadian";
else if(arg=="mp17") pla = "/d/guanwai/xiaowu";
else if(arg=="mp18") pla = "/d/tiezhang/guangchang";
else if(arg=="mp19") pla = "/d/yandang/luoyan6";
else if(arg=="mp20") pla = "/d/feitian/daochang";
else if(arg=="mp21") pla = "/d/wudujiao/dating";
else if(arg=="nj") pla = "/d/jinling/zhongxin";
else if(arg=="mp22") pla = "/d/xiaoyao/qingcaop";
else if(arg=="mp23") pla = "/d/beijing/dating";
else if(arg=="mp24") pla = "/d/nanshaolin/ting";
else if(arg=="mp25") pla = "/d/kunlun/shanmen";
else if(arg=="mp26") pla = "/d/dali/wangfugate";
     if(arg=="job1") pla = "/d/welcome/welcome";
     if(arg=="job2") pla = "/d/city/yaopu";
     if(arg=="job3") pla = "/quest/famu/shulin2";
     if(arg=="job4") pla = "/quest/changxi/xiyuan";
     if(arg=="job5") pla = "/d/welcome/fight3";
     if(arg=="job6") pla = "/quest/songhuo/huowo";
     if(arg=="job7") pla = "/d/pingan/bingyin";
     if(arg=="job8") pla = "/d/henshan/huiyan";
     if(arg=="job9") pla = "/d/migong/migong3";
     if(arg=="job10") pla = "/d/city/kedian";
if(arg=="yqz") pla = "/d/city/qianzhuang";
if (arg=="ct1") pla = "/d/zhongzhou/shizhongxin";
if (arg=="ct2") pla = "/d/datong/shizilukou";
if (arg=="ct3") pla = "/d/cloud/cross";
if (arg=="ct4") pla = "/d/xueting/guangchang";
if (arg=="ct5") pla = "/d/zhongyuan/chuzhou/nan_men";
if (arg=="ct6") pla = "/d/tianshui/cross";
if (arg=="ct7") pla = "/d/zuojiacun/lu5";
if (arg=="ct8") pla = "/d/xiyu/gaochang/center";
if (arg=="ct9") pla = "/d/xibei/xingqing/road4";
if (arg=="ct10") pla = "/d/xibei/liangzhou/center";
if (arg=="sy") pla = "/d/suiye/zhongxinguanchang";

if (!pla)
{
               message_vision(HIR
"�����˰��죬�ŷ���$NҪȥ�ĵط�����û�Ǹ�վ��\n���$N���������������ˤ�ñ������ף�\n"NOR, me);
}
     if (me->move(pla)) {
       message_vision(HIC"\n���ˣ������ȵ�ͣ�����£�$N�����������Գ�����˻��֡�\n"NOR,me);
if( me->query("age") <= 18 )
           me->add("jing",-10);
 else   me->add("jing",-30);
}
     return 1;
}

int do_xx(string arg)
{
object me = this_player();
	if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        if (!me->query("hyvip") && !wizardp(me))
                return notify_fail("�Բ���ֻ�л�Ա�������ܴ˷���\n");

/*
if (me->query("age") > 19)
return notify_fail("ֻ�л�Ա������!\n");
if (me->query("str") > 40)
return notify_fail("ֻ�л�Ա������!\n");
if (me->query("dex") > 40)
return notify_fail("ֻ�л�Ա������!\n");
*/
if (me->is_busy())
return notify_fail("������æ��\n");
if (me->is_fighting())
return notify_fail("�����ڴ�\n");

//if ((int)me->query("combat_exp") > 1500000 )
//return notify_fail("ֻ�л�Ա������!\n");

if ( (int)me->query("jing") < 30 || (int)me->query("qi") < 30 )
return notify_fail("�������̫���ˣ�û�취���С�!\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");



if (me->query_temp("working") >=1)
{
	write(""+me->query("name")+"���羲ˮ�����붨����\n");
}
else
{
	message_vision(YEL "$N�ó���Ա�������ڵ��Ͽ�ʼ��������!!\n" NOR,me);
	write(""+me->query("name")+"�������񣬿�ʼ�������С�\n");
}
	

	me->add_temp("working",1);
if (me->query("qi") < me->query("max_qi"))
me->add("qi",me->query("max_qi")/5);
if (me->query("jing") < me->query("max_jing"))
me->add("jing",me->query("max_jing")/5);
me->start_busy(8);

if (me->query_temp("working") >=6)
	call_out("work_end", 1, me);

return 1;
}


int work_end(object me)
{
	object ob1;
	int add_exp,add_pot,add_score;
	me->delete_temp("working");
	write("������������,����һЩ��������\n");
	me->receive_damage("jing",me->query("jing")/8);
	me->receive_damage("qi",me->query("qi")/8);

//		add_exp=3+random(3);
//		add_pot=2+random(2);
//if ((int)me->query("combat_exp",1) < 1200000 && !me->query("zhuanshen") && !me->query("zhuanbest")  && !me->query("guard/flag"))
//{
		add_exp=5+random(5);
		add_pot=3+random(3);

//}

		add_score=1+random(1);
		me->add("combat_exp",add_exp);
		me->add("potential",add_pot);
		//me->add("score",add_score);
		ob1 = new("/clone/money/silver");
		ob1->set_amount(add_score);
		ob1->move(me);	
		tell_object(me,HIW"��õ���:"
			+ chinese_number(add_exp) + "��ʵս���飬"
			+ chinese_number(add_pot) + "��Ǳ�ܡ�\n"NOR);		
				
	if ( me->query_temp("working") ) me->delete_temp("working");
	return 1;
}






string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 )
		return chinese_number(value) + "��Ǯ";
	else
		return chinese_number(value/100) + "��"
			+ (value%100? "��" + chinese_number(value%100) + "��Ǯ": "");
}

void pay_player(object who, int amount)

{
	object ob;
	if( amount < 1 ) amount = 1;
	if( amount/10000 ) {
		ob = new(GOLD_OB);
		ob->set_amount(amount/10000);
		ob->move(who);
		amount %= 10000;
	}
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who);
	}
}

int do_pawn(string arg)
{
	object ob;
	string term, *terms;
	string data;
	int value, pawn_count, i;
	int rvalue;
	mapping pawn;
	object me;
	me = this_player();
	pawn = me->query("pawn");
	if( !arg || !(ob = present(arg, this_player())) )
	{
	write("��Ŀǰ�䵱����Ʒ�У�\n");
	if( !mapp(pawn) ||   !sizeof(pawn) )
		write("\tû���κε䵱����Ʒ��\n");
	else {
                        terms = keys(pawn);
                        for(i=0; i<sizeof(terms); i++)
                                printf("%-3s��  %-15s  ������%s\n", terms[i], pawn[terms[i]],
			value_string(((int)me->query("vpawn/"+terms[i]))* 3/4));
              }
	return 1;
	}
	if( ob->query("money_id") )	return notify_fail("��Ҫ����Ǯ����\n");
        if( ob->query("equipped") || ob->query("no_drop") )     return notify_fail("�����ɵ����ˣ�\n");
        if( ob->query("no_pawn") )     return notify_fail("������������ˣ�\n");
	if (ob->query("food_supply"))
		return notify_fail("ʣ��ʣ���������Լ��ðɡ�\n");
	if (ob->query("liquid/remaining"))
		return notify_fail("ʣ��ʣ���������Լ��ðɡ�\n");
        if (ob->query("ownmake"))
                return notify_fail("�����ı����ҿ�����\n");


	value = ob->query("value");
	if( !value )
        return notify_fail("������������ֵ�ܶ�Ǯ��\n");

	if( !value || value < 30)
        return notify_fail("������������ֵ�ܶ�Ǯ��\n");

	if( !(value/4) ) return notify_fail("������������ֵ�ܶ�Ǯ��\n");
        if( mapp(pawn) && sizeof(pawn))
                {
                        terms = keys(pawn);
                        if(sizeof(terms) > MAX_PAWN)
                        return notify_fail("���ѵ䵱̫����Ʒ�ˡ�\n");
			for(i=0; i<sizeof(terms); i++)	
			{
			pawn_count = i;
                        if(!((int) me->query("vpawn/" + sprintf("%d", i))))
                         break;
                        else pawn_count = i+1;
			}
                }
	else pawn_count = 0;
	term = ob->query("name");
	data = base_name(ob)+ ".c";
	me->set("pawn/"+ sprintf("%d",pawn_count),  term);
	me->set("vpawn/"+sprintf("%d",pawn_count), ob->query("value"));
	me->set("fpawn/"+sprintf("%d",pawn_count), data);
	me->save();
	message_vision("$N����һ�����̣������ϵ�" + ob->query("name") + "�ó����䵱��"
		+ value_string(value * 25 / 100) + "��\n", this_player());

	pay_player(this_player(), value * 25 / 100 );
	destruct(ob);

	return 1;
}


void pay_him(object who, int amount)

{
	object ob;
        object cash, tencash, gold, silver, coin;
        tencash = present("tenthousand-cash_money", who);
        cash = present("thousand-cash_money", who);
        gold = present("gold_money",who);
        silver = present("silver_money",who);
        coin = present("coin_money",who);
	if(tencash) destruct(tencash);
        if(cash) destruct(cash);
        if(gold) destruct(gold);
        if(silver) destruct(silver);
        if(coin) destruct(coin);


	if( amount < 1 ) amount = 1;
	if( amount/10000 ) {
		ob = new(GOLD_OB);
		ob->set_amount(amount/10000);
		ob->move(who);
		amount %= 10000;
	}
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who);
	}
}

int affordable(object me, int amount)
{
        int total;
        object cash, tencash, gold, silver, coin;

        tencash = present("tenthousand-cash_money", me);
        cash = present("thousand-cash_money", me);
        gold = present("gold_money",me);
        silver = present("silver_money",me);
        coin = present("coin_money",me);

        total = 0;
        if( tencash) total += tencash->value();
        if( cash) total += cash->value();
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value();

        if( total < amount ) return 0;

        return total;
}
int do_redeem(string arg)
{
        int num;
        int amount;
        string ob_file;
        object ob;
        object me;
        int afford;
        if( !arg || sscanf(arg, "%d", num)!=1 )
                return notify_fail("ָ���ʽ��redeem <��Ʒ���>\n");
        me = this_player();
        amount = (int) me->query("vpawn/" + sprintf("%d", num));
        if( !amount )
                return notify_fail("�������Ʒ�����\n");
        amount = amount * 3 /4;
        if( afford = affordable(me, amount) ) {
                pay_him(me, afford-amount);
                ob_file = me->query("fpawn/"+sprintf("%d",num));
                ob = new(ob_file);
                ob->move(me);
                me->delete("pawn/"+sprintf("%d",num));
                me->delete("vpawn/"+sprintf("%d",num));
                me->delete("fpawn/"+sprintf("%d",num));
		me->save();
                message_vision("$N����һ�����̣������$n��\n", me, ob);
                return 1;
        } else
                return notify_fail("���Ǯ������\n");

}