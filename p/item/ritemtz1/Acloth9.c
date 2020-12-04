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
	      set_name("[31mÓã³¦Ö®·ş×°[2;37;0m¡ï", ({ "yuchang cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
[31mÓã³¦ÇáÇÉÎŞ±È£¬ÄÜ¿ªÌì±ÙµØ£¬µ´Ñı³ıÄ§£¡
[2;37;0mÕâÊÇÒ»¼şÓÉÎŞ±È¼áÓ²µÄ¾«¸Ö¼ÓÉÏ[1;33mÄ¾ÃŞ»¨[2;37;0mÖÆ³É£¬ÖØÒ»½ï¾ÅÁ½ÈıÇ®µÄ[31mÓã³¦Ö®·ş×°[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[1;36mÕ¶Ñı·üÄ§[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;34mµç[2;37;0m:[1;35m¾øÊÀ[2;37;0m [1;36mÈË[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;31mÄ§[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ÌìÓî:[33mºÜ¸ß[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
ÌåÁé:[33mºÜ¸ß[2;37;0m ÍşÁ¦:[1;36mÍêÃÀ[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 36000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",40);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 620);
    set("armor_prop/defense", 44);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 71);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",11);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",8);
    set("wtypeL",8);
    
    
                set("skill", ([
                        "name": "leg",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 19);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";