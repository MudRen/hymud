// follow.c
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob;
	int i;
	mapping inquirys;
	string *inqu;
	          string pla;
	          me = this_player();
if (!me->query_temp("xmud")) return notify_fail("?\n");
	          
	if( !arg ) return notify_fail("$move\n
����(gc) ����(tam)  Ȫ��(qz) ����(sz)  ����ׯ(gyz)
��վ(dache)����Ǯׯ(yqz) �������(majiu)���ݵ���(dp) 
ʢ��(yj) ���(wg)   ����(km)  ����(hz) ����(lz)
����(bl) ����(fz)   ����(cz)  ����(yx) ����(ly)  
����(yy) ����(tg)   ��ƽ(yp)  ����(jl) ����(wx)
�Ž�(jj) ʢ��(sj)   ��Զ(ny)  ��ɳ(cs) �ϲ�(nc)
����(gy) �½�(xj)   ����(xz)  ����(xiz)̫ԭ(ty)
�Ϸ�(hf) �ձ�(jp)   ����(an)  ����(cx) ����(nj) 
�书(wgz)����(yl)   ����(gw)  ����(dx) ����(ca)
�ɶ�(cd) ����(laz)  ����(jz)  ����(xy) ����(dl)
����(shl)��ɽ(hs)   ����(lj)  �䵱(wd) ����(mj)  
����(sld)����(xx)   ѩɽ(xs)  ���(mp7)��ɽ(mp6)
��ü(em) ȫ��(quz)  ����(bt)  ��Ĺ(gm) ����(mp10)
����(mp11)���(mp12) ÷ׯ(mp8) ����(mp9)�һ�(thd)
�컨(mp1) ���(mp2)  ̩ɽ(mp3) ��ɽ(mp4)��ɽ(mp5)
�μ�(mp26)Ľ��(mp13) ����(mp14)����(mp15)����(mp16)
����(mp17)����(mp18) ����(mp19)����(mp20)�嶾��(mp21)
��ң(mp22)����(mp23) ����(mp25)������(mp24)��Ҷ(sy)
����(ct1) ��ͬ(ct2)  �����(ct3)ѩͤ��(ct4)����(ct5)
��ˮ(ct6) ��ͤ��(ct7)�߲�(ct8)  �����(ct9)����(ct10)\n$#\n");

if( me->query("jing") < 30 )
               return notify_fail("�㾫�񲻹���ʢ��û����������\n");
if( me->query_temp("pending/team"))
               return notify_fail("�����ͱ�������أ�\n");	

if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR 
       ||environment(me)->query("magicset")==1
       ||environment(me)->query("maze")
       )
			return notify_fail("�˴��޷�ʹ�ã� ����ȫ�ǵ�·����������һ�ҡ�\n");               
if (me->is_busy())
return notify_fail("������æ��\n");
if (me->is_fighting())
return notify_fail("�����ڴ�\n");

  if( !wizardp(me) && me->is_fighting()  ) 
          return notify_fail("��ôΣ�գ��ǻ���ʱ��ȥ����?\n");

          if (me->query_temp("pigging_seat"))
                return notify_fail("���뿪�����������ж���\n");
          if( environment(me)->query("light_up"))
               return notify_fail("�ĳ��ﲻ������!!\n");

//if( !environment(me)->query("outdoors") ) 
//          return notify_fail(HIY"\n�������������\n"NOR);
message_vision(HIY
"$N���˸���򣬲���ʾ�����е����ֳ���Ʊ�����ǣ��������\n"+
"$N�����������һ������ඡ���ֻ�����ɱ���ȥ������\n\n"NOR, me);
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
else if(arg=="yqz") pla = "/d/city/qianzhuang";
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
               if (!pla) {
               message_vision(HIR
"�����˰��죬�ŷ���$NҪȥ�ĵط�����û�Ǹ�վ��\n���$N���������������ˤ�ñ������ף�\n"NOR, me);
}
     if (me->move(pla)) {
       message_vision(HIC"\n���ˣ������ȵ�ͣ�����£�$N�����������Գ�����˻��֡�\n"NOR,me);
if (!me->is_busy()) me->start_busy(2);
}
return 1;
}
int help (object me)
{
        write(@HELP
HELP
);
        return 1;
}
