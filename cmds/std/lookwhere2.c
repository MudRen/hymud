
string getwhere(object ob)
{
       object tmpobj,where, *ob_list,me,obtwo,obthree,tob;

        object item,room;

        string output,outputt,dis,alt,dir,local,tlocal,ck,playout;
        
        int i;

        int x,y,z,x0,y0,z0;

        int realdis;
	 mixed map,mapt;

        int tmp;
        string *dir1;
        string *dir2;

	string str="";
output="δ֪����";

dir2=explode(base_name(ob),"/");

if (dir2[1]=="baituo")  

output="����ɽ";

else if (dir2[1]=="binghuodao")  

	output="����";

else if (dir2[1]=="city")  

	output="����";

else if (dir2[1]=="city2" || dir2[1]=="beijing"  || dir2[1]=="huanggon"  || dir2[1]=="huanggong" || dir2[1]=="beihai")  

	output="������";

else if (dir2[1]=="city4" || dir2[1]=="changan")   

	output="������";

else if (dir2[1]=="dali")  

	output="����";

else if (dir2[1]=="emei")  

	output="��üɽ";

else if (dir2[1]=="foshan")  

	output="��ɽ";

else if (dir2[1]=="gaibang")  

	output="ؤ��";

else if (dir2[1]=="gaochang")  

	output="�߲��Թ�";

else if (dir2[1]=="guanwai")  

	output="����";

else if (dir2[1]=="guiyun")  

	output="����ׯ";

else if (dir2[1]=="gumu")  

	output="��Ĺ��";

else if (dir2[1]=="hangzhou")  

	output="����";

else if (dir2[1]=="heimuya")  

	output="��ľ��";

else if (dir2[1]=="hengshan")  

	output="��ɽ";

else if (dir2[1]=="henshan")  

	output="��ɽ";

else if (dir2[1]=="huanghe")  

	output="�ƺӾ���";

else if (dir2[1]=="huashan")  

	output="��ɽ";

else if (dir2[1]=="jinshe")  

	output="����ɽ��";

else if (dir2[1]=="lingjiu")  

	output="���չ�";

else if (dir2[1]=="lingzhou")  

	output="����";

else if (dir2[1]=="meizhuang")  

	output="÷ׯ";

else if (dir2[1]=="mingjiao")  

	output="����";

else if (dir2[1]=="qingcheng")  

	output="���ɽ";

else if (dir2[1]=="quanzhen")  

	output="ȫ����";

else if (dir2[1]=="quanzhou")  

	output="Ȫ��";

else if (dir2[1]=="shaolin")  

	output="������";

else if (dir2[1]=="shenlong")  

	output="������";

else if (dir2[1]=="songshan")  

	output="��ɽ";

else if (dir2[1]=="suzhou")  

	output="����";

else if (dir2[1]=="taishan")  

	output="̩ɽ";

else if (dir2[1]=="taohua")  

	output="�һ���";

else if (dir2[1]=="tianlongsi")  

	output="������";

else if (dir2[1]=="wanjiegu")  

	output="��ٹ�";

else if (dir2[1]=="wudang")  

	output="�䵱ɽ";

else if (dir2[1]=="xiakedao")  

	output="���͵�";

else if (dir2[1]=="xiangyang")  

	output="������";

else if (dir2[1]=="xiaoyao")  

	output="��ң��";

else if (dir2[1]=="xingxiu")  

	output="���޺�";

else if (dir2[1]=="xueshan")  

	output="ѩɽ��";

else if (dir2[1]=="xuedao")  

	output="��ѩɽ";

else if (dir2[1]=="mr")  

	output="Ľ������";

else if (dir2[1]=="kunlun")  

	output="����ɽ";

else if (dir2[1]=="tiezhang")  

	output="������";

else if (dir2[1]=="huizhu")  

	output="���岿��";

else if (dir2[1]=="yinju")  

	output="һ�ƴ�ʦ��";

else if (dir2[1]=="menggu")  

	output="�ɹŲ�ԭ";

else if (dir2[1]=="qianjin")  

	output="����ǧ��¥";

else if (dir2[1]=="lingshedao")  

	output="���ߵ�";

else if (dir2[1]=="ruzhou")  

	output="���ݳ�";

else if (dir2[1]=="kunming")  

	output="����";

else if (dir2[1]=="jingzhou")  

	output="����";

else if (dir2[1]=="yanjing")  

	output="�ྩ";

else if (dir2[1]=="lanzhou" || dir2[1]=="lanzhouchen")  

	output="����";

else if (dir2[1]=="jyguan")  

	output="��������";

else if (dir2[1]=="changcheng")  

	output="������";

else if (dir2[1]=="fairyland")  

	output="��÷ɽׯ";

else if (dir2[1]=="sdxl")  

	output="��ħ�������Ĺ";

else if (dir2[1]=="jqg")  

	output="�����";

else if (dir2[1]=="nio")  

	output="ţ�Ҵ�";

else if (dir2[1]=="feihu")  

	output="��������";

else if (dir2[1]=="wuguan")  

	output="�������";

else if (dir2[1]=="village")  

	output="��ɽ��";

else if (dir2[1]=="taohuacun")  

	output="�һ���";

else if (dir2[1]=="pingan")  

	output="ƽ����";

else if (dir2[1]=="lingxiao")  

	output="������";

else if (dir2[1]=="wudujiao")  

	output="�嶾��";

else if (dir2[1]=="hj")  

	output="��ɽ������ԭ";
else if (dir2[1]=="dali/yuxu")  

	output="���������";
else if (dir2[1]=="dali/wuliang")  

	output="��������ɽ";
else if (dir2[1]=="huanghe/yyd")  

	output="�ƺ�����";
else if (dir2[1]=="kaifeng")  

	output="�����";
else if (dir2[1]=="feitian")  

	output="����������";
else if (dir2[1]=="japan")  

	output="�ձ���";
else if (dir2[1]=="tangmen")  

	output="����";
else if (dir2[1]=="luoyang")  

	output="������";

else if (dir2[1]=="chengdu" || dir2[1]=="city3")  

	output="�ɶ�";

else if (dir2[1]=="baihuagu")  

	output="�ٻ���";

else if (dir2[1]=="heizhao")  

	output="����";

else if (dir2[1]=="jiaxing")  

	output="����";

else if (dir2[1]=="shiliang")  

	output="�¼�ׯ";

else if (dir2[1]=="wuyi")  

	output="����ɽ��";

else if (dir2[1]=="yanping")  

	output="��ƽ��";
	

if (dir2[1]=="jiangling")  
{
	output="�����";
}

if (dir2[1]=="yueyang")  
{
	output="������";	
}

if (dir2[1]=="qilian")  
{
	output="����ɽ";	
}

if (dir2[1]=="shouxihu")  
{
	output="������";	
}

if (dir2[1]=="wuxi")  
{
	output="������";	
}

if (dir2[1]=="yixing")  
{
	output="���˳�";	
}
if (dir2[1]=="taiwan")  
{
	output="̨�����";	
}
if (dir2[1]=="nanyang")  
{
	output="��������";	
}
if (dir2[1]=="nanshaolin")  
{
	output="�����ֵ���";	
}

if (dir2[1]=="cangzhou")  
{
	output="���ݵ���";	
}

if (dir2[1]=="tanggu")  
{
	output="�����ǵ���";	
}

if (dir2[1]=="yunhe")  
{
	output="�������˺�";	
}

if (dir2[1]=="hainan")  
{
	output="���ϵ�";	
}

if (dir2[1]=="jindezheng")  
{
	output="������";	
}

if (dir2[1]=="yandang")  
{
	output="�㵴ɽ";	
}

if (dir2[1]=="jinling")  
{
	output="�����";	
}

if (dir2[1]=="sandboy")  
{
	output="����ũ��";	
}

if (dir2[1]=="huangshan")  
{
	output="��ɽ";	
}

if (dir2[1]=="yubifeng")  
{
	output="��ʷ�";	
}

if (dir2[1]=="quanzhouchen")  
{
	output="Ȫ�ݳ���";	
}

if (dir2[1]=="qingzh")  
{
	output="��ظ�ԭ";	
}

if (dir2[1]=="changbaishan" || dir2[1]=="gaoli")  
{
	output="���� ����ɽ";	
}

if (dir2[1]=="annan")  
{
	output="����";	
}

if (dir2[1]=="taiyuan")  
{
	output="̫ԭ";	
}

if (dir2[1]=="hefei")  
{
	output="�Ϸ�";	
}

if (dir2[1]=="jiujiang")  
{
	output="�Ž�";	
}

if (dir2[1]=="baling")  
{
	output="����";	
}

if (dir2[1]=="xinjiang")  
{
	output="�½�";	
}
if (dir2[1]=="dingxiang")  
{
	output="����";	
}
if (dir2[1]=="suiye")  
{
	output="��Ҷ";	
}


if (dir2[1]=="mayi")  
{
	output="���ر߽�";	
}
if (dir2[1]=="xuzhou")  
{
	output="���ݳ�";	
}
if (dir2[1]=="jinan")  
{
	output="���ϳ�";	
}
if (dir2[1]=="guizhou")  
{
	output="������";	
}

if (dir2[1]=="nanchang")  
{
	output="�ϲ���";	
}


if (dir2[1]=="changsha")  
{
	output="��ɳ��";	
}


if (dir2[1]=="zhongzhou")  
{
	output="���ݳ�";	
}

if (dir2[1]=="xizang" || dir2[1]=="zangbei")  
{
	output="���ػ�ر�";	
}

if (dir2[1]=="cloud" )  
{
	output="���������";	
}

if (dir2[1]=="xueting" )  
{
	output="����ѩͤ��";	
}

if (dir2[1]=="ny" )  
{
	output="������Զ��";	
}

if (dir2[1]=="fengtian" )  
{
	output="����ʢ����";	
}

if (dir2[1]=="yanmen" )  
{
	output="���Ź�";	
}

if (dir2[1]=="linzhi" )  
{
	output="������֥����";	
}

if (dir2[1]=="datong" )  
{
	output="��ͬ��";	
}

if (dir2[1]=="tianshui" )  
{
	output="��ˮ��";	
}

if (dir2[1]=="heifeng" )  
{
	output="�ڷ�կ";	
}

if (dir2[1]=="paiyun" )  
{
	output="����կ";	
}


if (dir2[1]=="yeyangzai" )  
{
	output="Ұ��կ";	
}


if (dir2[1]=="jinghai" )  
{
	output="������";	
}

if (dir2[1]=="zuojiacun" )  
{
	output="��ͤ��";	
}


if (dir2[1]=="houjizhen" )  
{
	output="���";	
}

if (dir2[1]=="huayin" )  
{
	output="ͭɽ��";	
}

if (dir2[1]=="lumaji" )  
{
	output="¹��";	
}


if (dir2[1]=="xiyu/gaochang" || dir2[1]=="xiyu/hami" || dir2[1]=="xiyu")  
{
	output="����߽�";	
}

if (dir2[1]=="xibei/desert" || dir2[1]=="xibei/kongdong" || dir2[1]=="xibei/liangzhou" || dir2[1]=="xibei/xingqing" || dir2[1]=="xibei")  
{
	output="�����߽�";	
}

if (dir2[1]=="zhongyuan/chuzhou" || dir2[1]=="zhongyuan" )  
{
	output="��ԭ����";	
}

if (dir2[1]=="xinan/after_qingcheng" || dir2[1]=="xinan/cunzi" || dir2[1]=="xinan")  
{
	output="�����Ĵ�";	
}

if (dir2[1]=="loulan" )  
{
	output="¥��";	
}

if (dir2[1]=="biancheng" )  
{
	output="�߳�";	
}

if (dir2[1]=="quicksand" )  
{
	output="��ɳĮ";	
}

if (dir2[1]=="tieflag/qianfo" || dir2[1]=="tieflag" || dir2[1]=="tieflag/palace" || dir2[1]=="tieflag/bat" || dir2[1]=="tieflag/chuenyu")  
{
	output="��������";	
}

if (dir2[1]=="taiping" )  
{
	output="̫ƽ��";	
}

if (dir2[1]=="eren/eren2" || dir2[1]=="eren" )  
{
	output="���˹�";	
}
return output;
}