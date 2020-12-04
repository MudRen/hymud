// hubo.c
#include <ansi.h>
inherit F_CLEAN_UP;
#include "/quest/givehdgift.c"
mapping migongs = ([
"/d/kunming/dxiaolu": "migong0",
"/d/baling/edao5": "migong1",
"/d/tanggu/gangkou": "migong2",
"/d/taiyuan/road1": "migong3",
"/d/yanping/fuqiao1": "migong4",
"/d/hangzhou/baiti": "migong5",
"/d/tiezhang/road-3": "migong6",
"/d/qingzh/road8": "migong7",
"/d/baling/edao10": "migong8",
"/d/kunming/nanmen": "migong9",
"/d/kunming/pubu": "migong10",
"/d/taiwan/riyuetan": "migong11",
"/d/kunming/shilin2": "migong12",
"/d/suzhou/yanyutang": "migong13",
"/d/xinan/leshan": "migong14",
"/d/jinan/road2": "migong15",
"/d/city4/apanggong": "migong16",
"/d/changcheng/nroad1": "migong17",
"/d/qilian/yumenguan": "migong18",
"/d/xizang/birdroad2": "migong19",
"/d/kaifeng/wroad3": "migong20",
"/d/hangzhou/road4": "migong21",
"/d/hangzhou/suti7": "migong22",
"/d/huangshan/taoyuan": "migong23",
"/d/huangshan/lianhua": "migong34",
"/d/fuzhou/shulin": "migong25",
"/d/taiyuan/sroad6": "migong26",
"/d/hangzhou/shiwudong": "migong27",
"/d/hangzhou/shuiledong": "migong28",
"/d/hangzhou/shanlu4": "migong29",
"/d/kunming/qingshilu2": "migong31",
"/d/henshan/hsroad9": "migong32",
"/d/city4/road4": "migong33",
"/d/taiyuan/road4": "migong34",
"/d/taiyuan/road5": "migong35",
"/d/yanping/road1": "migong36",
"/d/xinan/shanlu09": "migong37",
"/d/taiyuan/nroad1": "migong38",
"/d/hangzhou/hupaoquan": "migong39",
"/d/lanzhou/caroad8": "migong40",
"/d/xingxiu/xxroad1": "migong41",
"/d/lanzhouchen/road3": "migong42",
"/d/lanzhou/caroad2": "migong43",
"/d/xinjiang/aiding": "migong44",
"/d/huangshan/mroad2": "migong45",
"/d/fuzhou/yushan": "migong46",
"/d/changsha/road1": "migong47",
"/d/changsha/eroad3": "migong48",
"/d/fuzhou/fzroad4": "migong49",
"/d/guizhou/dadao2": "migong50",
"/d/resort/smallroad": "migong51",
"/d/xinan/shanlu07": "migong52",
"/d/xuedao/sroad2": "migong53",
"/d/xinan/shanlu11": "migong54",
"/d/guizhou/tulu2": "migong55",
"/d/guizhou/beimen": "migong56",
"/d/city4/road5": "migong57",
"/d/tianshui/yidao5": "migong58",
"/d/xinjiang/chairong": "migong59",
"/d/kunming/qingshilu": "migong60",
"/d/taishan/baozang": "migong61",
"/d/taishan/yaocan": "migong62",
"/d/taishan/daimiao": "migong63",
"/d/taishan/aishen": "migong64",
"/d/huangshan/feicui": "migong65",
"/d/huangshan/mingxuan": "migong66",
"/d/huangshan/chayuan": "migong67",
"/d/songshan/tianzhongge": "migong68",
"/d/songshan/chaotian": "migong69",
"/d/songshan/shuyuan": "migong70",
"/d/huashan/chaoyang": "migong71",
"/d/huashan/sheshen": "migong72",
"/d/huashan/lianhua": "migong73",
"/d/huashan/yuntai": "migong74",
"/d/huashan/yunu": "migong75",
"/d/henshan/zhurongfeng": "migong76",
"/d/henshan/wangyuetai": "migong77",
"/d/henshan/wangritai": "migong78",
"/d/hengshan/hufengkou": "migong79",
"/d/hengshan/xuangengsong": "migong80",
"/d/changsha/yanzixiang": "migong81",
"/d/changsha/eroad2": "migong82",
"/d/changsha/dongmen": "migong83",
"/d/henshan/hsroad8": "migong84",
"/d/jiangling/huanghelou": "migong85",
"/d/jingzhou/sanxia1": "migong86",
"/d/jiangling/shennongjia": "migong87",
"/d/jingzhou/sanxia2": "migong88",
"/d/hainan/underhill2": "migong89",
"/d/hainan/road4": "migong90",
"/d/hainan/pubu": "migong91",
"/d/hainan/underhill3": "migong92",
"/d/xinjiang/emin": "migong93",
"/d/xinjiang/tulu3": "migong94",
"/d/xinjiang/sichou3": "migong95",
"/d/xinjiang/goudi": "migong96",
"/d/xizang/deadneck": "migong97",
"/d/zangbei/mount2": "migong98",
"/d/taiwan/hongmaocheng": "migong99",
"/d/taiwan/lugang": "migong100",
]);

void zujinpc(object me,object obj);
int main(object me)
{
	string msg,fname;
	int count,a,exp,pot,killer;
 object obj,maxpot,badguy,fang,who,killern,env,env2,*inv;
 int i,j,maxskill,fskill,rw,sizeinv;
         object *team,boss;
         string week, month, year, day, time,hydata;
    if( me->is_busy() )
	return notify_fail("你的动作还没有完成。\n");
    if( me->is_fighting() )
        return notify_fail("你正打得热闹呢!。\n");
    if( (int)me->query("jing") < 70 ) return notify_fail("你的精不够！\n");
    if( (int)me->query("qi") < 70 ) return notify_fail("你的精不够！\n");

env=environment(me);
fname=base_name(env);



if (userp(me) && me->query_temp("nmp1tg"))
{
if (fname==me->query_temp("nmp1tg"))
{
fskill=me->query_skill("force",1);
if (!fskill) fskill=100;
	me->start_busy(2);

if( !environment(me)->query("no_fight"))
{
if (random(8)==1 && me->query("combat_exp") > 2000000)

{
obj=new("/quest/menpaijob/shenlong/menggu"); 
obj->move(environment(me));
obj->do_copy(me,maxpot,2);
obj->set("title",HIY"巡逻官兵"NOR);
obj->set("usename",me->query("name"));
me->start_busy(1);
message_vision(HIY"附近走来一名很凶狠的巡逻官兵！\n"NOR, obj);
message_vision(HIR"$N说道: 你这个妖人竟敢打探地方军政，我特来消灭你这等妖人！\n"NOR, obj);
obj->kill_ob(me);
me->kill_ob(obj);
return notify_fail("先把这恶官兵消灭再说吧？\n");
}
}
msg = GRN "$N与附近的江湖人物，混在一起，说了一会把"+environment(me)->query("short")+GRN"这里发生的事的情况大致了解了！\n" NOR;
exp=90+random(10);    
exp=exp/2+18;
addnl(me,"exp",exp);
me->start_busy(8);
me->delete_temp("nmp1tg");
message_vision(msg, me);
return 1;
}
}



if (userp(me) && me->query_temp("dl_job_target"))
{
if (fname==me->query_temp("dl_job_target"))
{
fskill=me->query_skill("force",1);
if (!fskill) fskill=100;
	me->start_busy(2);
rw=random(199);
fskill=fskill/2+1;
killern=new("/quest/menpai/mandl");
killern->move(environment(me));
killern->initlvl(fskill);
killern->setn(rw);
killern->fight_ob(me);

me->kill_ob(killern);
tell_object(me, me->query("name")+"发现附近有个" + killern->query("name") + "在为恶四方。\n" NOR);
	tell_object(me, killern->query("name")+"突然向你杀来！\n");
me->set_temp("dl_job_target",0);
me->delete_temp("dl_job_target");
return 1;
}
}

if (!me->query_temp("roomjob") )
	{
//if (wizardp(me) || me->query("id")=="hxsdtest") tell_object(me, "你在"+fname+"。\n");

if (migongs[fname]) 
	{
	//tell_object(me, "你在"+migongs[fname]+"。\n");
env2=load_object("/p/migong/migong/"+migongs[fname]);
if (me->query("mpgx",1)<=1)  return notify_fail("你发现一个可以探险的地方，但你的门派贡献不够！\n");
if (env2->query("mgstart")==0 || !env2->query("mgstart")) return notify_fail("你发现一个可以探险的地方，但好像才有人探险过，里面没有东西！\n");
if (me->query_skill("force",1) <= env2->query("mglvl",1)) return notify_fail("你发现一个可以探险的地方，但你的武功太低不敢进去！\n");
if (me->query_skill("force",1) > (env2->query("mglvl",1)+100)) return notify_fail("你发现一个可以探险的地方，但你的武功太高，没必要进去了！\n");

                inv=all_inventory(me);
                sizeinv=sizeof(inv);
        
                while (sizeinv--)
                {
                        if (inv[sizeinv]->is_character())  
                                return notify_fail("你身上背了一个人，先去把事做完吧! \n");
                
                }

if (env2) 
	{
		//sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);
		//hydata=year+month+day;
		//if ( me->query("nmgdata")==hydata ) 
			me->add("mpgx",-1);
		env2->set("mgstart",0);
	me->move(env2);
//me->set("nmgdata",hydata);
	tell_object(me, "你发现这里有点异常的地方，你一跃飞身走了进去。\n");
return 1;
}
}
}

    if( !me->query_temp("roomjob") ) return notify_fail("你没有这个任务啊！\n");

    //if( !me->query_condition("roomjob") ) return notify_fail("你这个任务已经过期了！\n");

    if (environment(me)->query("short") !=me->query_temp("roomjob"))
     {
         tell_object(me,HIR"好像是叫你到"+me->query_temp("roomjob")+HIR"去刺探情报的吧！\n"NOR);
          return 1;
     }

seteuid(getuid());
    msg = GRN "$N与附近的江湖人物，混在一起，说了一会把"+environment(me)->query("short")+GRN"这里发生的事的情况大致了解了！\n" NOR;

//return notify_fail("对比:"+base_name(environment(me))+".c"+":"+me->query_temp("nhdjob2tg")+"\n");

if(me->query_temp("nhdjob2lb")=="边疆御敌" && userp(me)
 && (me->query_temp("nhdjob2tg")==base_name(environment(me))+".c" || environment(me)->query("short") ==me->query_temp("roomjob")))
{

tell_object(me,HIR"一阵马蹄声后，一大队敌军来到了附近!\n"+
NOR);
j=random(4);
if (j==0)
for(i=0;i<=5;i++)
{
                badguy = new("/quest/task/japan");
                badguy->move(environment(me));
zujinpc(me,badguy);	
badguy->random_move();
}

if (j==1)
for(i=0;i<=5;i++)
{
                badguy = new("/quest/task/jinbing");
                badguy->move(environment(me));
zujinpc(me,badguy);	
badguy->random_move();
}
if (j==2)
for(i=0;i<=5;i++)
{
                badguy = new("/quest/task/menggu");
                badguy->move(environment(me));
zujinpc(me,badguy);	
badguy->random_move();
}
if (j==3)
for(i=0;i<=5;i++)
{
                badguy = new("/quest/task/xixia");
                badguy->move(environment(me));
zujinpc(me,badguy);	
badguy->random_move();
}




me->delete_temp("nhdjob2lb");
me->delete_temp("roomjob");
me->delete_temp("nhdjob2tg");
me->delete_temp("nhdjob2sc");
me->delete_temp("nhdjob2en");

me->add("max_neili",1);
me->add_temp("nhdjobsl",1);
if (me->query("shen")>0) me->add("shen",200);
if (me->query("shen")<0) me->add("shen",-200);
tell_object(me,"通过巡查边疆 你增加了一点内力上限和二百点神!\n");
if (random(9)==0)
	 {
tell_object(me,"你的门派贡献增加了!\n");
	 me->add("mpgx",1);
}
return 1;
}

if(me->query_temp("nhdjob2lb")=="门派守护" && userp(me)
&& (me->query_temp("nhdjob2tg")==base_name(environment(me))+".c" || environment(me)->query("short") ==me->query_temp("roomjob")))
{

tell_object(me,HIR"一阵马蹄声后，一大队黑道人物来到了附近!!\n"+
NOR);
me->delete_temp("nhdjob2lb");
me->delete_temp("roomjob");
me->delete_temp("nhdjob2tg");
me->delete_temp("nhdjob2sc");
me->delete_temp("nhdjob2en");
for(i=0;i<=5;i++)
{
                badguy = new("/quest/task/killer");
                badguy->move(environment(me));
zujinpc(me,badguy);	
                badguy->random_move();
}
me->add("max_neili",1);
me->add_temp("nhdjobsl",1);
if (me->query("shen")>0) me->add("shen",200);
if (me->query("shen")<0) me->add("shen",-200);
tell_object(me,"通过巡查门派 你增加了一点内力上限和二百点神!\n");
if (random(9)==0)
	 {
tell_object(me,"你的门派贡献增加了!\n");
	 me->add("mpgx",1);
}
return 1;
}


if(me->query_temp("hdjob2lb")=="江湖" && userp(me)
&& (me->query_temp("hdjob2tg")==base_name(environment(me))+".c" || environment(me)->query("short") ==me->query_temp("roomjob")))
{

tell_object(me,HIR"一阵马蹄声后，一大队黑道人物来到了附近!!\n"+
NOR);
me->delete_temp("hdjob2lb");
me->delete_temp("roomjob");
me->delete_temp("hdjob2tg");
me->delete_temp("hdjob2sc");
me->delete_temp("hdjob2en");

for(i=0;i<=5;i++)
{
                badguy = new("/quest/task/killer");
                badguy->move(environment(me));
zujinpc(me,badguy);	
badguy->random_move();
}


me->add("max_neili",1);
me->add_temp("hdjobsl",1);
if (me->query("shen")>0) me->add("shen",200);
if (me->query("shen")<0) me->add("shen",-200);
tell_object(me,"通过巡查门派 你增加了一点内力上限和二百点神!\n");
if (random(5)==0)
	 {
tell_object(me,"你的门派贡献增加了!\n");
	 me->add("mpgx",1);
}
me->set_temp("tjobstart",0);
me->delete_temp("tjobstart");
return 1;
}


if(me->query_temp("hdjob2lb")=="悬赏" && userp(me)
)
{

tell_object(me,HIR"一阵马蹄声后，一个黑道人物来到了附近向你杀来!!\n"+
NOR);
me->delete_temp("hdjob2lb");
me->delete_temp("roomjob");
me->delete_temp("hdjob2tg");
me->delete_temp("hdjob2sc");
me->delete_temp("hdjob2en");
me->add("max_neili",1);
me->add_temp("hdjobsl",1);
if (me->query("shen")>0) me->add("shen",200);
if (me->query("shen")<0) me->add("shen",-200);
tell_object(me,"通过追杀黑道人物你增加了一点内力上限和二百点神!\n");
fang = new("/quest/menpai/boss");
	fang->move(environment(me));	
	maxskill=(int)me->query_skill("force",1)+10;
	if (maxskill<=200) maxskill=200;
	if (!me->query("zhuanshen") && me->query("combat_exp",1) <=6000000) maxskill=maxskill*3/4;
	fang->initlvl(maxskill);
        fang->set("combat_exp",me->query("combat_exp",1));
        i=me->query_temp("team_count");
        if (!i) i=sizeof(me->query_team());
        if (!i) i=1;
        fang->set("qi",fang->query("max_qi")*i);
        fang->set("eff_qi",fang->query("max_qi")*i);
        fang->set("max_qi",fang->query("max_qi")*i);

        fang->set("jing",fang->query("max_jing")*i);
        fang->set("eff_jing",fang->query("max_jing")*i);
        fang->set("max_jing",fang->query("max_jing")*i);

        fang->set("neili",fang->query("max_neili")*i);
        fang->set("max_neili",fang->query("max_neili")*i);
      
        
        fang->set("str", me->query("str"));
        fang->set("dex", me->query("dex"));
        fang->set("per", me->query("per"));
        
	fang->kill_ob(me);
	me->kill_ob(fang);
me->set_temp("tjobstart",0);
me->delete_temp("tjobstart");
return 1;
}

if(me->query_temp("nhdjob2lb")=="情报刺探" && userp(me)
 && me->query_temp("nhdjob2tg")==environment(me)->query("short"))
{
exp=1300+random(188);
if ((int)me->query_temp("nhdjobsl",1)>=1) exp=exp+((int)me->query_temp("hndjobsl",1)*30);
if (me->query("hyvip",1)==4) 
exp=exp/2+300;
else
exp=exp/2;


tell_object(me,HIR"你成功的完成了一项江湖互动任务!\n"+
NOR);
me->delete_temp("nhdjob2lb");
me->delete_temp("roomjob");
me->delete_temp("nhdjob2tg");
me->delete_temp("nhdjob2sc");
me->delete_temp("nhdjob2en");
me->clear_condition("taskjob_busy");
addnl(me,"exp",exp);
me->add("max_neili",1);
me->add_temp("nhdjobsl",1);
if (me->query("shen")>0) me->add("shen",200);
if (me->query("shen")<0) me->add("shen",-200);
tell_object(me,"你增加了一点内力上限和二百点神!\n");
if (random(9)==0)
	 {
tell_object(me,"你的门派贡献增加了!\n");
	 me->add("mpgx",1);
}
if ((int)me->query_temp("tjoblx",1)<7)
{
	who=me;
if (random(2)==0)
"/adm/daemons/taskd"->give_gift3(1,who,me);
else
"/adm/daemons/taskd"->give_gift3(2,who,me);
if (me->query_temp("nhdjob2sc"))
message_vision("$N通过这次刺探，得到了一个任务:\n" + me->query_temp("nhdjob2sc") + "。\n", me);
}

me->set_temp("tjobstart",0);
me->set_temp("tjobk",0);
me->delete_temp("tjobstart");
me->delete_temp("tjobk");
return 1;
}


if(me->query_temp("hdjob2lb")=="刺探" && userp(me)
 && me->query_temp("hdjob2tg")==environment(me)->query("short"))
{
exp=1300+random(188);
if ((int)me->query_temp("hdjobsl",1)>=1) exp=exp+((int)me->query_temp("hdjobsl",1)*30);
if (me->query("hyvip",1)==4) 
exp=exp/2+300;
else
exp=exp/2;
tell_object(me,HIR"你成功的完成了一项玩家互动任务!\n"+
NOR);

me->delete_temp("hdjob2lb");
me->delete_temp("roomjob");
me->delete_temp("hdjob2tg");
me->delete_temp("hdjob2sc");
me->clear_condition("taskjob_busy");
addnl(me,"exp",exp);
me->add_temp("hdjobsl",1);
me->add("max_neili",2);
if (me->query("shen")>0) me->add("shen",500);
if (me->query("shen")<0) me->add("shen",-500);
tell_object(me,"你增加了二点内力上限和五百点神!\n");
if (random(5)==0)
	 {
tell_object(me,"你的门派贡献增加了!\n");
	 me->add("mpgx",1);
}
me->set_temp("tjobstart",0);
me->delete_temp("tjobstart");
return 1;
}

if( !environment(me)->query("no_fight"))
{
if (random(30)==1 && me->query("combat_exp") > 2000000)
//if (me->query("combat_exp") > 2000000)
{
obj=new("/quest/menpaijob/shenlong/menggu"); 
obj->move(environment(me));
obj->do_copy(me,maxpot,2);
obj->set("title",HIY"巡逻官兵"NOR);
obj->set("usename",me->query("name"));
me->start_busy(1);
message_vision(HIY"附近走来一名很凶狠的巡逻官兵！\n"NOR, obj);
message_vision(HIR"$N说道: 你这个妖人竟敢打探地方军政，我特来消灭你这等妖人！\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
return notify_fail("先把这恶官兵消灭再说吧？\n");
}
}
me->apply_condition("roomjob",0);
me->clear_condition("roomjob",0);
me->clear_condition("taskjob_busy");
me->set_temp("roomjob",0);
me->delete_temp("roomjob");
if (me->query("family/family_name"))
{
a=FAMILY_D->query_family_fame(me->query("family/family_name"));
}
else
{
a=random(2000)+100;	
}	
if (a> 10 && random(10)==0) 
{	
exp=(int)a/10+10;
pot=(int)exp*2/3+10;
        tell_object(me, me->query("family/family_name")+"在江湖上的威望是" + chinese_number(a) + "。\n" NOR);
addnl(me,"exp",exp);

}
exp=68+random(120)+(int)me->query_temp("menpaijob")/2;
pot=55+random(100)+(int)me->query_temp("menpaijob")/3;
exp=exp/2;
        		if ((int)me->query_temp("menpaikill")==1)
		{
me->add_temp("menpaijob",1);
		me->delete_temp("menpaikill");	
		}
    message_vision(msg, me);
if (exp < 90) exp=88+random(22);    
if (!me->query("zhuanshen") && me->query("combat_exp",1)<=8000000 ) exp=exp*5;
    addnl(me,"exp",exp);
fskill=me->query_skill("force",1);
if (fskill >=100)
{
	me->start_busy(2);
rw=random(199);
fskill=fskill/2+1;
killern=new("/quest/menpai/man");
killern->move(environment(me));
killern->initlvl(fskill);
killern->setn(rw);
if (me->query("zhuanshen"))
{	
killern=new("/quest/menpai/man");
killern->move(environment(me));
killern->initlvl(fskill);
killern->setn(rw);
}
tell_object(me, me->query("name")+"发现附近有几个" + killern->query("name") + "很可疑。\n" NOR);

}

    me->delete("quest");
    me->set("quest", 0);
    me->start_busy(8);
    me->receive_damage("jing", 50);
    me->receive_damage("qi", 50);
    return 1;
}


void zujinpc(object me,object obj)
{   

	int maxpot;
	int maxexp;
	int maxskill;
	int i;
	mapping hp_status, skill_status;
        string *sname;
        if (!me) return;
	maxskill=1+me->query_skill("force",1)*2/3;
	maxpot=me->query_temp("maxpot");
	maxexp=me->query("combat_exp",1);
        if (maxskill<100)
        maxskill=100;
        i=me->query_temp("team_count");
        if (!i) i=sizeof(me->query_team());
        if (i==0) i=1;
        if (!i) i=1;


         obj->set("combat_exp",maxexp);
        obj->set("str", me->query("str"));
        obj->set("dex", me->query("dex"));
        obj->set("per", me->query("per"));
        obj->set("qi", me->query("max_qi")*i);
        obj->set("eff_qi", me->query("max_qi")*i);
        obj->set("max_qi", me->query("max_qi")*i);
        obj->set("eff_jing", me->query("max_jing")*i);
        obj->set("max_jing", me->query("max_jing")*i);
        obj->set("jing", me->query("max_jing")*i);
        obj->set("neili", me->query("max_neili")*i);
        obj->set("max_neili", me->query("max_neili")*i);
if (mapp(skill_status = obj->query_skills()))
{
skill_status = obj->query_skills();
sname = keys(skill_status);
for (i = 0; i < sizeof(skill_status); i++)
obj->set_skill(sname[i], maxskill);
}

}

int help(object me)
{
        write(@HELP
指令格式 : citan
 
这个指令可以让你在任务中，来刺探情报的。
 
HELP
    );
    return 1;
}
