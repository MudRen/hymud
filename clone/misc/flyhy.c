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
	set_name(YEL"会员背包"NOR, ({"member beg", "beg"}));
        set("unit", "只");
set("long", YEL"会员专用，包里面看上去有永远吃不完的干粮。\n
你可以吃喝休息乘车,并可以修行(he,ci,xiuxi,chen,xiuxing,当(mpawn)取(mredeem)。可以乘(chen)：
车站(dache) 扬州马厩(majiu) 扬州当铺(dp) 扬州(gc) 北京(tam) 泉州(qz)  苏州(sz)归云庄(gyz) 
盛京(yj) 武馆(wg) 昆明(km) 杭州(hz)  灵州(lz) 巴陵(bl) 福州城(fz) 沧州(cz) 宜兴(yx) 洛阳(ly)  
岳阳(yy) 塘沽(tg) 延平(yp) 江陵(jl)无锡城(wx) 九江(jj) 盛京(sj)   宁远(ny) 长沙(cs) 南昌(nc)
贵阳(gy) 新疆(xj) 徐州(xz) 西藏(xiz) 太原(ty) 合肥(hf) 日本(jp) 安南(an) 高丽(cx)   金陵(nj) 
武功镇(wgz)伊犁(yl)关外(gw)  定襄(dx) 长安(ca)   成都(cd) 兰州(laz)荆州(jz) 襄阳(xy)大理(dl)
少林(shl) 华山(hs) 灵鹫(lj) 武当(wd) 明教(mj) 神龙(sld) 星宿(xx) 雪山(xs) 段家(mp26)
峨眉(em) 全真(quz)白驼山(bt)古墓(gm) 海南(mp10)侠客(mp11)崆峒(mp12)梅庄(mp8)靖海(mp9) 桃花(thd)
红花(mp1)  青城(mp2)泰山派(mp3)嵩山(mp4) 衡山(mp5)恒山(mp6) 苗家(mp7) 慕容(mp13) 唐门 (mp14)
日月(mp15) 凌霄(mp16) 胡家(mp17) 铁掌(mp18) 落雁(mp19) 飞天(mp20)  五毒教(mp21) 逍遥(mp22) 
天地会(mp23) 南少林(mp24)昆仑派(mp25)\n"NOR      
);
	set("no_get",1);
	set("no_drop",1);
		set("no_get", 1);
		set("no_put", 1);
		set("no_drop", 1);
             set("value", 0);
             set("material", "steel");
             set("no_drop", "这样东西不能离开你。\n");
        setup();
}

int do_eat2()
{
int exp;
object me = this_player();


if (me->is_busy())
return notify_fail("你正在忙？\n");
if (me->is_fighting())
return notify_fail("你正在打？\n");

tell_object(me,YEL "现在你的经验是"+me->query("combat_exp",1)+"。\n" NOR);

exp=(int)me->query("combat_exp",1);
if (exp<=80000)
tell_object(me,YEL "现在适合你的任务是新手任务："+HIR"chen job1\n"NOR+HIR"ask lao about job\n"+HIR"相关帮助help nbjob\n"NOR);

if (exp>80000 && exp<=180000)
tell_object(me,YEL "现在适合你的任务是磨药任务："+HIR"chen job2\n"NOR+HIR"ask ping about job\n"+HIR"相关帮助help moyao\n"NOR);

if (exp>=180000 && exp<=300000)
tell_object(me,YEL "现在适合你的任务是巡城任务："+HIR"chen job7\n"NOR+HIR"ask wang about job\n"+HIR"相关帮助help xunchen\n"NOR);

if (exp>80000 && exp<=500000)
tell_object(me,YEL "现在适合你的任务是伐木任务："+HIR"chen job3\n"NOR+HIR"ask songque about job\n"+HIR"相关帮助help kanshu\n"NOR);

if (exp>=500000 && exp<=1000000)
tell_object(me,YEL "现在适合你的任务是唱戏任务："+HIR"chen job4\n"NOR+HIR"ask guan about job\n"+HIR"相关帮助help changxi\n"NOR);

if (exp>=180000 && exp<=1500000)
tell_object(me,YEL "现在适合你的任务是打猎任务："+HIR"chen job5\n"NOR+HIR"south 后杀死猎物获得奖励\n"+HIR"相关帮助help dalie\n"NOR);

if (exp>=1500000 && exp<=2500000)
tell_object(me,YEL "现在适合你的任务是采花任务："+HIR"chen job8\n"NOR+HIR"ask tian about job\n"+HIR"相关帮助help tianjob\n"NOR);

if (exp>80000 && exp<=2500000)
tell_object(me,YEL "如果加入了门派，可以做对练任务"+HIR"找到门派的任务吏\n"NOR+HIR"输入job后duilian 本门人员\n"+HIR"相关帮助help geren\n"NOR);

if (exp>1500000)
tell_object(me,YEL "你已经有一定经验了，介绍几个重要的任务给你:\n"+HIR"江湖任务:help taskjobs\n"NOR+HIR"门派任务：help geren \n"+HIR"其他任务help aboutquest\n"NOR);

if (exp>=300000 )
tell_object(me,YEL "现在你可以去迷宫探险了："+HIR"chen job9\n"NOR+"相关帮助help migong\n"NOR);

if (exp>=300000 )
tell_object(me,YEL "现在你可以去挑战洞窟了："+HIR"chen job10\n"+HIR"ask bei chou about challenge\n"NOR+"相关帮助help boss 新手试炼-挑战洞窟\n"NOR);

if (exp>2500000)
tell_object(me,YEL "已经可以自由闯荡江湖了。天高任鸟飞，海阔凭鱼跃。\n"NOR);


me->start_busy(1);
return 1;
}


int do_eat(string arg)
{
object me = this_player();
	if (!id(arg))
                return notify_fail("你要吃什么？\n");
        if (!me->query("hyvip") && !wizardp(me))
                return notify_fail("对不起，只有会员才能享受此服务！\n");

if (me->is_busy())
return notify_fail("你正在忙？\n");
if (me->is_fighting())
return notify_fail("你正在打？\n");

if (me->query("food")*1.5 > me->max_food_capacity()
&& me->query("water")*1.5 > me->max_water_capacity())
return notify_fail("你现在不饿啦!\n");

message_vision(YEL "$N拿出干粮大吃大喝了一顿!!\n" NOR,me);
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
                return notify_fail("你要用什么？\n");

        if (!me->query("hyvip") && !wizardp(me))
                return notify_fail("对不起，只有会员才能享受此服务！\n");



if (me->is_busy())
return notify_fail("你正在忙？\n");
if (me->is_fighting())
return notify_fail("你正在打？\n");

if (me->query("qi") > me->query("max_qi")
&& me->query("jing") > me->query("max_jing")
)
return notify_fail("你现在不累啦!\n");
message_vision(YEL "$N拿出会员背包铺在地上休息一会!!\n" NOR,me);
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
return notify_fail("你休息了一会!\n");
}

  int do_fly(string arg)
{

          string pla;
          object me = this_player();
if( me->query("jing") < 30 )
               return notify_fail("你精神不够旺盛，没力气做车马！\n");
if( me->query_temp("pending/team"))
               return notify_fail("你正和别人组队呢！\n");				

        if (!me->query("hyvip") && !wizardp(me))
                return notify_fail("对不起，只有会员才能享受此服务！\n");

if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR 
       ||environment(me)->query("magicset")==1
       ||environment(me)->query("maze")
       )
			return notify_fail("此处无法使用！ 附近全是道路，让你心神一乱。\n");

/*
if( !environment(me)->query("no_fight") && me->query("combat_exp") > 900000)
{
  message_vision("只有在安全区域才能找到马车!!!\n"
                 ,me);
      	return 1;
}

if( !environment(me)->query("no_fight") && me->query("str") > 31)
{
  message_vision("只有在安全区域才能找到马车!!!\n"
                 ,me);
      	return 1;
}

if( !environment(me)->query("no_fight") && me->query("zhuanshen"))
{
  message_vision("只有在安全区域才能找到马车!!!\n"
                 ,me);
      	return 1;
}
*/

if (me->is_busy())
return notify_fail("你正在忙？\n");
if (me->is_fighting())
return notify_fail("你正在打？\n");

if ( me->query_temp("in_guard")   || me->query_temp("player_working") || me->query_temp("shouwei"))
return notify_fail("你正在做任务!\n");
          if (!arg)
              return notify_fail("你想去哪里？\n");
          if( !wizardp(me) && me->is_fighting()  ) 
          return notify_fail("这么危险，那还有时间去坐马车?\n");

          if (me->query_temp("pigging_seat"))
                return notify_fail("先离开拱猪桌才能行动。\n");
          if( environment(me)->query("light_up"))
               return notify_fail("赌场里不能坐马车!!\n");

//if( !environment(me)->query("outdoors") ) 
//          return notify_fail(HIY"\n室外才能坐马车。\n"NOR);


          else {
          message_vision(HIY
"$N叫了个马夫，并出示了手中的武林车马票，马夫牵来了马车。\n"+
"$N坐上马车，大喝一声“走喽”，只见马夫驾驶着马车飞奔而去。。。\n\n"NOR, me);
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
"马车跑了半天，才发觉$N要去的地方根本没那个站。\n结果$N被马夫扔了下来，摔得鼻青脸肿！\n"NOR, me);
}
     if (me->move(pla)) {
       message_vision(HIC"\n到了！马车稳稳地停到地下，$N跳下了马车。对车夫挥了挥手。\n"NOR,me);
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
                return notify_fail("你要用什么？\n");

        if (!me->query("hyvip") && !wizardp(me))
                return notify_fail("对不起，只有会员才能享受此服务！\n");

/*
if (me->query("age") > 19)
return notify_fail("只有会员才能用!\n");
if (me->query("str") > 40)
return notify_fail("只有会员才能用!\n");
if (me->query("dex") > 40)
return notify_fail("只有会员才能用!\n");
*/
if (me->is_busy())
return notify_fail("你正在忙？\n");
if (me->is_fighting())
return notify_fail("你正在打？\n");

//if ((int)me->query("combat_exp") > 1500000 )
//return notify_fail("只有会员才能用!\n");

if ( (int)me->query("jing") < 30 || (int)me->query("qi") < 30 )
return notify_fail("你的身体太累了，没办法修行。!\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");



if (me->query_temp("working") >=1)
{
	write(""+me->query("name")+"心如静水，渐入定境。\n");
}
else
{
	message_vision(YEL "$N拿出会员背包铺在地上开始打坐修行!!\n" NOR,me);
	write(""+me->query("name")+"收摄心神，开始打坐修行。\n");
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
	write("终于修行完了,你获得一些奖励。”\n");
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
		tell_object(me,HIW"你得到了:"
			+ chinese_number(add_exp) + "点实战经验，"
			+ chinese_number(add_pot) + "点潜能。\n"NOR);		
				
	if ( me->query_temp("working") ) me->delete_temp("working");
	return 1;
}






string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 )
		return chinese_number(value) + "文钱";
	else
		return chinese_number(value/100) + "两"
			+ (value%100? "又" + chinese_number(value%100) + "文钱": "");
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
	write("你目前典当的物品有：\n");
	if( !mapp(pawn) ||   !sizeof(pawn) )
		write("\t没有任何典当的物品。\n");
	else {
                        terms = keys(pawn);
                        for(i=0; i<sizeof(terms); i++)
                                printf("%-3s：  %-15s  赎银：%s\n", terms[i], pawn[terms[i]],
			value_string(((int)me->query("vpawn/"+terms[i]))* 3/4));
              }
	return 1;
	}
	if( ob->query("money_id") )	return notify_fail("你要当「钱」？\n");
        if( ob->query("equipped") || ob->query("no_drop") )     return notify_fail("这样可当不了！\n");
        if( ob->query("no_pawn") )     return notify_fail("这个东西当不了！\n");
	if (ob->query("food_supply"))
		return notify_fail("剩菜剩饭留给您自己用吧。\n");
	if (ob->query("liquid/remaining"))
		return notify_fail("剩菜剩饭留给您自己用吧。\n");
        if (ob->query("ownmake"))
                return notify_fail("这样的宝物我可买不起。\n");


	value = ob->query("value");
	if( !value )
        return notify_fail("这样东西并不值很多钱。\n");

	if( !value || value < 30)
        return notify_fail("这样东西并不值很多钱。\n");

	if( !(value/4) ) return notify_fail("这样东西并不值很多钱。\n");
        if( mapp(pawn) && sizeof(pawn))
                {
                        terms = keys(pawn);
                        if(sizeof(terms) > MAX_PAWN)
                        return notify_fail("你已典当太多物品了。\n");
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
	message_vision("$N找了一个当铺，把身上的" + ob->query("name") + "拿出来典当了"
		+ value_string(value * 25 / 100) + "。\n", this_player());

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
                return notify_fail("指令格式：redeem <物品标号>\n");
        me = this_player();
        amount = (int) me->query("vpawn/" + sprintf("%d", num));
        if( !amount )
                return notify_fail("有这个物品标号吗？\n");
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
                message_vision("$N找了一个当铺，赎回了$n。\n", me, ob);
                return 1;
        } else
                return notify_fail("你的钱不够。\n");

}