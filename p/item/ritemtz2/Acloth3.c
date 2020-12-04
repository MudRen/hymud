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
	      set_name("[1;32m无极之服装[2;37;0m★", ({ "wuji cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[1;32m此物已达出神入化，登峰造极，神乎其神之境界！俗说万物归宗，便是这“无极”！
[2;37;0m这是一件由无比坚硬的精钢加上[1;37m蚕丝[2;37;0m制成，重二斤九两三钱的[1;32m无极之服装[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[31m无与伦比[2;37;0m的防护力！
上面刻了几个古符号：
[36m木[2;37;0m:[1;32m魔王[2;37;0m [1;31m魔[2;37;0m:[1;31m开元[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 天宇:[32m粗糙[2;37;0m 天渊:[32m粗糙[2;37;0m 巧制:[1;36m完美[2;37;0m 
白石:[33m很高[2;37;0m 不老:[35m标准[2;37;0m 

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
		set("armor_prop/strength",31);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",32);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 42);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 500);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 51);
    set("armor_prop/jingli", 51);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",9);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",13);
    
    
                set("skill", ([
                        "name": "club",
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