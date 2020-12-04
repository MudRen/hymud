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
	      set_name("[1;37mÁé·ÉÕ½¼×[2;37;0m", ({ "taibai cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
[1;37m
		ÕÔ¿ÍçÏºúÓ§  Îâ¹³ËªÑ©Ã÷		Òø°°ÕÕ°×Âí  ìªí³ÈçÁ÷ĞÇ
		Ê®²½É±Ò»ÈË  Ç§Àï²»ÁôĞĞ		ÊÂÁË·÷ÒÂÈ¥  Éî²ØÉíÓëÃû
		ÏĞ¹ıĞÅÁêÒû  ÍÑ½£Ï¥Ç°ºá		½«ÖË¡õÖìº¥  ³ÖõüÈ°ºîÙø
		Èı±­ÍÂÈ»Åµ  ÎåÓüµ¹ÎªÇá		ÑÛ»¨¶úÈÈáá  ÒâÆøËØÄŞÉú
		¾ÈÕÔ»Ó½ğé³  ºªµ¦ÏÈÕğ¾ª		Ç§Çï¶ş×³Ê¿  ĞúºÕ´óÁº³Ç
		×İËÀÏÀ¹ÇÏã  ²»²ÑÊÀÉÏÓ¢		Ë­ÄÜÊé¸óÏÂ  °×Ê×Ì«Ğş¾­
[2;37;0mÕâÊÇÒ»¼şÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0m¼ÓÉÏ[37mÌì²ÏË¿[2;37;0mÖÆ³É£¬ÖØÆß½ïÎåÁ½ÎåÇ®µÄ[1;37mÌ«°×Ö®·ş×°[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[1;36mÕ¶Ñı·üÄ§[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[37mÌì[2;37;0m:[31m¾«ÖÂ[2;37;0m [1;31mÄ§[2;37;0m:[35m±ê×¼[2;37;0m [1;33m½ğ[2;37;0m:[31m¾«ÖÂ[2;37;0m [36mÄ¾[2;37;0m:[1;31mÎŞË«[2;37;0m [1;35m·ç[2;37;0m:[1;33mÌìÊ¥[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
ÖÜÌì:[31m¾«ÖÂ[2;37;0m ³¤Éú:[33mºÜ¸ß[2;37;0m ²»ÀÏ:[31m¾«ÖÂ[2;37;0m ÍşÁ¦:[31m¾«ÖÂ[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m¶ÎÒ©Ê¦[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÊÖ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "yellow");
		set("ownername", "¶ÎÒ©Ê¦");
		set("value", 25000);
		set("armor_prop/intelligence",56);
		set("armor_prop/strength",56);
		set("armor_prop/karey",48);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",40);
    set("armor_prop/dodge", 48);
    set("armor_prop/parry", 56);
    set("armor_prop/attack", 48);


    set("armor_prop/armor", 964);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 60);
    set("armor_prop/qi", 47);
    set("armor_prop/jing", 60);
    set("armor_prop/jingli", 60);
    set("armor_prop/damage", 454);

    set("wtypeA",6);
    set("wtypeB",12);
    set("wtypeC",0);
    set("wtypeD",6);
    set("wtypeE",0);
    set("wtypeF",10);
    set("wtypeG",6);
    set("wtypeH",0);
    set("wtypeI",6);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "hand",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 16);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";