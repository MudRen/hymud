#include <ansi.h>
 
inherit F_CLEAN_UP;
int time_period(int timep, object me);
int main(object me, string arg)
{
	      string str,str2;
	      int k;
        int nowtime = time();
        mapping quest;
        object ob;
        ob=me;

//        if(!(quest =  me->query("quest")))
//               return notify_fail("������û���κ�����\n");    
               
if (me->query("jobtg",1) && me->query("jobtime"))
{
	if ((int)me->query("jobtime",1)==1)
		str2="������������quest��"+me->query_temp("mpjobn1",1)+"/"+me->query("jobtg",1)+"��������(help geren)";
		
	if ((int)me->query("jobtime",1)==2)
		str2="������������job��"+me->query_temp("mpjobn3",1)+"/"+me->query("jobtg",1)+"��������(help geren)";
		
	if ((int)me->query("jobtime",1)==3)
		str2="����սʤ"+me->query_temp("mpjobn4",1)+"/"+me->query("jobtg",1)+"�����(��ͬIP)  ";
		
	if ((int)me->query("jobtime",1)==4)
		str2="����"+me->query("jobtgn")+"��"+me->query_temp("mpjobn5",1)+"/"+me->query("jobtg",1)+"������ �ɵ�����(kantou)";
		
			if ((int)me->query("jobtime",1)==5)
		str2="���"+me->query_temp("mpjobn6",1)+"/"+me->query("jobtg",1)+"�������س����� (help guojob)";
		
	if ((int)me->query("jobtime",1)==6)
		str2="���"+me->query_temp("mpjobn7",1)+"/"+me->query("jobtg",1)+"�������������� (help wangjob)";
		
	if ((int)me->query("jobtime",1)==7)
		str2="���"+me->query_temp("mpjobn8",1)+"/"+me->query("jobtg",8)+"�� �����Ľ������� ɱ�����boss (help taskjobs)";
		
	if ((int)me->query("jobtime",1)==8)
		str2="���"+me->query_temp("mpjobn2",1)+"/"+me->query("jobtg",1)+"�θ������������ (help teamjob)";
		
	if ((int)me->query("jobtime",1)==9)
		str2="���"+me->query_temp("mpjobn9",1)+"/"+me->query("jobtg",1)+"�ιٸ�����       (help guanfu)";			

write("�����ڵ�ʦ��������:" + str2+"��\n");
}        
   if (me->query("quest"))
   	{
   		quest =  me->query("quest");
if (quest["quest"]==0 || me->query("songxin"))
{
write("�����ڵ�������:" + quest["quest_type"] + "��" + quest["quest_name"] + "����\n");
}
else
{
        write("�����ڵ�������" + quest["quest_type"] + "��" + quest["quest"] + "����\n");
}

        nowtime = (int) me->query("task_time") - time();
        if( nowtime  > 0 )
                time_period(nowtime, me);
        else
{
                   me->set_temp("menpaijob",0);
                   me->delete_temp("menpaijob");
write("�������Ѿ�û���㹻��ʱ����������ˡ�\n");
}
}
str="";                
if (me->query_temp("nhdjob2lb"))
{
    str += sprintf(HIR"��������:%s��help taskjobs\n"NOR, me->query_temp("nhdjob2sc"));
}

if (me->query_temp("hdjob2lb"))
{
str += sprintf("��������:%s��help hdjobs\n", me->query_temp("hdjob2sc"));
}


if (me->query_temp("obj/liangong"))
{
str += sprintf("��������help geren\n");
}

if (me->query("nbjob",1)<20)
{
str += sprintf("�Ŵ���������δ��ɡ�help nbjob\n");
}

if (me->query("nbjob",1)>=20 && me->query("nbjob",1)<50)
{
str += sprintf("������������δ��ɡ�help nbjob\n");
}

if (me->query_temp("xunchen"))
{
str += sprintf("Ѳ������help xunchen\n");
}
if (me->query_temp("findgirl"))
{
str += sprintf("�ﲮ������help tianjob\n");
}


if (me->query_condition("lyjob"))
{
str += sprintf("������������help lyjob\n");
}


if (me->query_condition("husong_busy") || me->query_temp("hu_song"))
{
str += sprintf("������������ Ŀ��"+me->query_temp("hstarget")+"��help wangjob\n");
}

if (me->query_condition("guanfu_task") || me->query_temp("guanfu_task"))
{
str += sprintf("�ٸ�����help guanfu\n");
}

if (me->query_temp("zzz_job_target") || (int)me->query_condition("zzz_mission"))
{
str += sprintf("�������� ��������(����)��help guojob\n");
}
if ((int)me->query_condition("zzz_busy"))
{
str += sprintf("�������� �������(����)��help guojob\n");
}
if (me->query_temp("mark/job_shadi"))
{
str += sprintf("�������� ��������(����)��help guojob\n");
}
if (me->query_temp("in_dart") || (int)me->query_condition("dart_limit"))
{
str += sprintf("�ּһ�������help hubiao\n");
}
if (me->query_temp("huang_job_target") || (int)me->query_condition("huang_mission"))
{
str += sprintf("��������help huangjob\n");
}
if (me->query_temp("job_moyao"))
{
str += sprintf("ĥҩ����help moyao\n");
}
if (me->query_temp("work/kan"))
{
str += sprintf("��������help kanshu\n");
}
if (me->query_temp("obj/changxi"))
{
str += sprintf("��Ϸ����help changxi\n");
}

if ((int)me->query_condition("pkjob"))
{
str += sprintf("��ս����\n");
}

if (me->query_temp("yljob2"))
{
str += sprintf("������Ԯ����help yunlongjob\n");
}

if (me->query_temp("yljob2/changxi"))
{
str += sprintf("������������help yljob2\n");
}

if (me->query_temp("xsjob2"))
{
str += sprintf("ѩɽ����Ů����help xuedaojob\n");
}
if (me->query_condition("xsjob"))
{
str += sprintf("ѩɽ��������help xueshanjob\n");
}
if (me->query_temp("������"))
{
str += sprintf("ѩɽ��������help mizongjob\n");
}

if (me->query_temp("xxjob2"))
{
str += sprintf("��������������help xingxiujob\n");
}
if (me->query_temp("flattering"))
{
str += sprintf("������������help xxpaimajob\n");
}

if (me->query_temp("singsong"))
{
str += sprintf("��ң��������help xysingjob\n");
}
if (me->query("kill_xiaoyao"))
{
str += sprintf("��ң�߱�ָ������help xiaoyaojob\n");
}

if (me->query_temp("wudujiao"))
{
str += sprintf("�嶾׽��������help wdjiaojob\n");
}
if (me->query_temp("wdhwjob"))
{
str += sprintf("�嶾ӭ������help wdyingjijob\n");
}

if (me->query("job/supervisor")) 
{
str += sprintf("�䵱��������help wdzhixiang\n");
}
if (me->query_temp("in_guard"))
{
str += sprintf("�䵱��������help wudangjob\n");
}

if (me->query_temp("job_name") || me->query_condition("tz_job") )
{
str += sprintf("������ɽ����help tzjob2\n");
}

if (me->query("taohuajob"))
{
str += sprintf("�һ����ٴ�����help taohuajob\n");
}


if (me->query_temp("tangmen"))
{
str += sprintf("��������������help tangmenjob\n");
}
if (me->query_temp("tmhw"))
{
str += sprintf("���Ż�������help tmhuchengjob\n");
}


if (this_player()->query_temp("sld"))
{
str += sprintf("������������help sldjob2\n");
}
if (me->query("kill_shenlong"))
{
str += sprintf("����42�¾�����help shenlongjob\n");
}

if (me->query_temp("wsdjob"))
{
str += sprintf("������ɮ������help slwsdjob\n");
}
if (me->query("shaolinjob"))
{
str += sprintf("���־�Ԯ����help shaolinjob\n");
}

if (me->query_temp("ryjob2/changxi"))
{
str += sprintf("������˵����help ryjob2\n");
}
if (me->query_temp("in_guard"))
{
str += sprintf("������������help riyuejob\n");
}


if (me->query_temp("qz_caiyao"))
{
str += sprintf("ȫ���ҩ����help qzcaiyao\n");
}
if (me->query_temp("qztjob") || me->query_condition("qztjob"))
{
str += sprintf("ȫ���ػ�����help quanzhenjob\n");
}


if (me->query_temp("mrjob"))
{
str += sprintf("Ľ����������help mrjob\n");
}
if (me->query_temp("mr_job")=="����")
{
str += sprintf("Ľ�ݽ�������help mrjob2\n");
}

if (me->query_temp("mj2job"))
{
str += sprintf("���̷�Ԫ����help mjjob2\n");
}
if (me->query("mjjob") )
{
str += sprintf("���̱�������help mjjob\n");
}

if (me->query_temp("lxhw"))
{
str += sprintf("������������help lxhuweijob\n");
}
if (me->query_temp("lingxiao"))
{
str += sprintf("����ɨѩ����help lingxiaojob\n");
}

if (me->query_temp("player_working"))
{
str += sprintf("������������help ljjob2\n");
}
if (me->query_temp("ljjob2"))
{
str += sprintf("���ս�Ԯ����help lingjiujob\n");
}


if (me->query_temp("xunshan"))
{
str += sprintf("��ɽѲɽ����help huashanjob\n");
}
if (me->query_temp("hs_times"))
{
str += sprintf("��ɽץ��������help zhuamonkey\n");
}

if (me->query_temp("gmjob"))
{
str += sprintf("��Ĺץ�۷�����help longnvjob\n");
}
if (me->query("kill_gumu"))
{
str += sprintf("��Ĺɱ�ɹ�Ԫ˧����help gumujob\n");
}


if (me->query_temp("shouwei"))
{
str += sprintf("ؤ����������help gaibangjob\n");
}
if (me->query_temp("begging"))
{
str += sprintf("ؤ����������help gbbegjob\n");
}



if (me->query_temp("fthwjob"))
{
str += sprintf("���커������help ftshouwei\n");
}

if (me->query_temp("smith/mo") || me->query_temp("smith/fenyao") || me->query_temp("smith/zhengli")) 
{
str += sprintf("����ҩ������help ftyaojob\n");
}


if (me->query_temp("emjob2") )
{
str += sprintf("��ü��ħ����help emeijob\n");
}
if (me->query_temp("dushi"))
{
str += sprintf("��üȰ������help xiuxingjob\n");
}


if (me->query_temp("garden_working"))
{
str += sprintf("�����������help dalijob2\n");
}
if (me->query_temp("tufei"))
{
str += sprintf("�����;�������help dalijob\n");
}

if (me->query_temp("qljob"))
{
str += sprintf("������ծ����help baituojob\n");
}
if (me->query_temp("bt2_song"))
{
str += sprintf("������������help btjob2\n");
}

if (me->query_temp("kl_working"))
{
str += sprintf("������������help btjob2\n");
}

if (me->query_temp("dl_job_target"))
{
str += sprintf("������������help geren\n");
}

if (me->query_temp("nmp1tg"))
{
str += sprintf("���ɴ�̽����Ŀ��:"+me->query_temp("nmp1chinese")+"��\n");
}

if (me->query_temp("nmp2tg"))
{
str += sprintf("���ɴ�ɱ����Ŀ��:"+me->query_temp("nmp2tg")+"��\n");
}
 write(str);
        return 1;
}
int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;
 
        if(d) time = chinese_number(d) + "��";
        else time = "";
 
        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
        tell_object(me,"�㻹��" + time + "ȥ�������\n");
        return 1;
}
 
int help(object me)
{
        write(@HELP
ָ���ʽ : quest  ���ָ�������ʾ���㵱ǰ������
HELP
        );
        return 1;
}