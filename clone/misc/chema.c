// more work needed to use this object to make poison
#include <ansi.h>
inherit ITEM;


void init()
{
          add_action ("do_fly","chema");
}

void create()
{
	set_name(YEL"���ֳ���Ʊ"NOR, ({"chema piao", "piao"}));
        set("unit", "��");
set("long", YEL"Ϊ�˷����ҡ���ͨ����(chema)����\n
 Ŀǰ�����ȥ�ĵط�������:
����(tam)  ����(dl) Ȫ��(qz) ����(shl) ��ɽ(hs) ����(lj) �䵱(wd) ����(mj)  ����(gc) ����(sld)
����(xx)   ѩɽ(xs) ��ü(em) ȫ��(quz)����ɽ(bt)��Ĺ(gm) ����(sz)����ׯ(gyz)����(xy) ����(dx)  
����(ca)   �ɶ�(cd) ����(laz)����(jz)  ʢ��(yj) ���(wg) ����(km) ����(hz)  ����(lz) ����(bl) 
���ݳ�(fz) ����(cz) ����(yx) ����(ly)  ����(yy) ����(tg) ��ƽ(yp) ����(jl)������(wx) �Ž�(jj)
ʢ��(sj)   ��Զ(ny) ��ɳ(cs) �ϲ�(nc)  ����(gy) �½�(xj) ����(xz) ����(xiz) ̫ԭ(ty) �Ϸ�(hf)
�һ�(thd) �ձ�(jp) ����(an) ����(cx)  ����(nj) ����(mp10)����(mp11)���(mp12)÷ׯ(mp8)����(mp9)
�컨(mp1)  ���(mp2)̩ɽ��(mp3)��ɽ(mp4) ��ɽ(mp5)��ɽ(mp6) ���(mp7) Ľ��(mp13) ���� (mp14)
����(mp15) ����(mp16) �书��(wgz)����(yl)����(gw)��վ(dache) �������(majiu) ���ݵ���(dp) 
����(mp17) ����(mp18) ����(mp19) ����(mp20)  �嶾��(mp21)\n"NOR  
);

             set("value", 500);
             set("material", "steel");
        setup();
}

  int do_fly(string arg)
{

          string pla;
          object me = this_player();
if( me->query("jing") < 30 )
               return notify_fail("�㾫�񲻹���ʢ��û����������\n");
if( me->query_temp("pending/team"))
               return notify_fail("�����ͱ�������أ�\n");				

if( !environment(me)->query("outdoors") ) 
          return notify_fail(HIY"\n�������������\n"NOR);

    if (me->is_fighting()) 
        return notify_fail("���������������!\n");
    if (me->is_busy()) 
        return notify_fail("������������!\n");
//if (me->query_temp("xhjob_start") || me->query_temp("wdhwjob") || me->query_temp("in_guard") || me->query_temp("job_name") ||me->query_temp("tmhw") || me->query_temp("qztjob") || me->query_temp("lxhw") || me->query_temp("player_working") || me->query_temp("shouwei"))
//return notify_fail("������������!\n");

if (me->query_temp("xhjob_start") || me->query_temp("wdhwjob") || me->query_temp("in_guard")   || me->query_temp("player_working") || me->query_temp("shouwei"))
return notify_fail("������������!\n");
          if (!arg)
              return notify_fail("����ȥ���\n");
          if( !wizardp(me) && me->is_fighting()  ) 
          return notify_fail("��ôΣ�գ��ǻ���ʱ��ȥ����?\n");

          if (me->query_temp("pigging_seat"))
                return notify_fail("���뿪�����������ж���\n");
          if( environment(me)->query("light_up"))
               return notify_fail("�ĳ��ﲻ������!!\n");


          else {
          message_vision(HIY
"$N���˸���򣬲������е����ֳ���Ʊ����������ǣ��������\n"+
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
               else {
               message_vision(HIR
"�����˰��죬�ŷ���$NҪȥ�ĵط�����û�Ǹ�վ��\n���$N���������������ˤ�ñ������ף�\n"NOR, me);
}
     if (me->move(pla)) {
       message_vision(YEL"\n���ˣ������ȵ�ͣ�����£�$N�����������Գ�����˻��֡�\n"NOR,me);
   me->set_temp("nbjob25",1);
   me->add("jing",-30);
   me->start_busy(3);
}
	destruct(this_object());
     return 1;
}