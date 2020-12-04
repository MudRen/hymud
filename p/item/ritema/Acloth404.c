#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;32m无极之服装[2;37;0m", ({ "wuji cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[1;32m此物已达出神入化，登峰造极，神乎其神之境界！俗说万物归宗，便是这“无极”！
[2;37;0m这是一件由绝对坚硬的精钢加上[1;37m蚕丝[2;37;0m制成，重一斤三两五钱的[1;32m无极之服装[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来绝对坚固，具有[35m极其可怕[2;37;0m的防护力！
上面刻了几个古符号：
[33m土[2;37;0m:[35m标准[2;37;0m [40m地[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 绝代:[32m粗糙[2;37;0m 天玄:[34m细碎[2;37;0m 巧制:[32m粗糙[2;37;0m 
体灵:[35m标准[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 25000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",30);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",26);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 420);
    set("armor_prop/defense", 55);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",5);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",12);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "blade",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 17);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";