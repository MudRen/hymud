// who2.c

inherit F_CLEAN_UP;
string  zuji(string str);
#include <ansi.h>
int main(object me, string str)
{
    object where, ob, *ob_list,obj,env;
    int i,j;
    string stri,envn;
    string *dir2;
    string room;
    seteuid(getuid());

    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());
    str = HIG"���    ���ID      ����       ����       \n"NOR;
    str += "��������������������������������������������������������������������������\n";
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        where = environment(ob);
if(!ob->query_temp("hdjoblb")) continue;
if(!ob->query_temp("hdjobtg")) continue;
if(!environment(ob)) continue;
    j++;
        str += sprintf(WHT"%-10s ",ob->name());
        str += sprintf(WHT"%-10s ",ob->query("id"));
//if (ob->query_temp("hdjoblb")=="����")
//str += sprintf(HIR"%-8s ", ob->query_temp("hdjoblb")+":"+ob->query_temp("hdjobtg"));
//else
        str += sprintf(HIR"%-8s ", ob->query_temp("hdjoblb"));

dir2=explode(base_name(where),"/");
room=zuji(dir2[1])+where->query("short");
    if (where) str += sprintf(HIM"%-10s\n"NOR,room);
    }
    str += HIG"��������������������������������������������������������������������������\n"NOR;
    str = sprintf("%s�� %d ����һ�������\n", str, j);
if (me->query_temp("hdjob2lb"))
{
    str += sprintf("�����ڵ�������:%s��", me->query_temp("hdjob2sc"));
if (me->query_temp("hdjob2lb")=="����" && me->query_temp("hdjob2tg"))
{
obj = find_player(me->query_temp("hdjob2tg"));
if (obj)
{
env=environment(obj);
if (env)
{
dir2=explode(base_name(env),"/");
envn=zuji(dir2[1])+"-"+env->query("short");
}
	
str += sprintf("Ŀ�������:%s��", envn);	
}
}	

}
    me->start_more(str);
    return 1;
}
int sort_user(object ob1, object ob2)
{
	//if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	//if( wizardp(ob2) && !wizardp(ob1) ) return 1;
	//if( wizardp(ob1) && wizardp(ob2) )
//		return (int)SECURITY_D->get_wiz_level(ob2) 
//			- (int)SECURITY_D->get_wiz_level(ob1);
	
//	return (int)ob2->query("mud_age") - (int)ob1->query("mud_age");
}
int help(object me)
{
        write(@HELP
ָ���ʽ��hdjob

��ѯ��ǰ��һ�������
HELP
        );
        return 1;
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

	output="�ٻ��ȡ����ӵ�";

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
	output="�������˺ӵ�";	
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
if (str=="fuzhou")  
{
	output="���ݳǸ�����";	
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
if (str=="newbie")  
{
	output="�������������";	
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
 